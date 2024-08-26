#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    networkAccessManager = new QNetworkAccessManager();
    currentQuizQuestion = -1;

    connect (networkAccessManager, &QNetworkAccessManager::finished, this, &MainWindow::aiAnswer);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete networkAccessManager;
}

void MainWindow::sendPromptToAI(QString prompt)
{
    QNetworkRequest request(QUrl(AI_GENERATE_POST_URL));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    qDebug() << "Prompt: " << prompt;

    QJsonObject json;
    json["model"] = AI_MODEL_NAME;
    json["prompt"] = prompt;
    json["stream"] = false;

    networkAccessManager->post(request, QJsonDocument(json).toJson());
}

void MainWindow::clearQuizData()
{
    currentQuizQuestion = -1;
    ui->questionCountLabel->clear();
    ui->getQuestionButton->setEnabled(true);
    ui->sendAnswerButton->setEnabled(false);
    ui->questionEdit->setText("To start a new quiz, click on the \"Get Question\" button");
}

void MainWindow::aiAnswer(QNetworkReply *reply)
{
    if (reply->error() == QNetworkReply::NoError) {
        QByteArray textReply = reply->readAll();
        QByteArray responseText = QJsonDocument::fromJson(textReply).object().value("response").toString().toUtf8();
        QJsonObject aiResponse = QJsonDocument::fromJson(responseText).object();

        qDebug() << "Response: " << responseText;

        if (aiResponse["type"] == "QUESTION_GENERATION") {
            Quiz question;
            question.quizQuestion = aiResponse["question"].toString();
            question.quizAIAnswer = aiResponse["answer"].toString();
            question.quizIsCorrect = false;
            question.quizUserAnswer.clear();

            ui->sendAnswerButton->setEnabled(true);
            ui->questionEdit->setText(question.quizQuestion);
            ui->questionCountLabel->setText(QString("Question: %1/%2").arg(QString::number(currentQuizQuestion + 1), QString::number(MAX_QUIZ_QUESTIONS)));
            quizQuestions[currentQuizQuestion] = question;
        } else if (aiResponse["type"] == "QUESTION_COMPARISON") {
            Quiz *question = &quizQuestions[aiResponse["questionId"].toInt()];
            question->quizIsCorrect = true;

            ui->getQuestionButton->setEnabled(true);
            ui->questionEdit->setText("Click on the \"Get question\" button to get a new question...");

            if (currentQuizQuestion == MAX_QUIZ_QUESTIONS - 1) {
                QString resultMessage = "You have successfully completed the test!\nYour score: %1/%2\n";
                int correctAnswers = 0;

                for (int index = 0; index < MAX_QUIZ_QUESTIONS; index++) {
                    question = &quizQuestions[index];

                    if (question->quizIsCorrect)
                        correctAnswers++;

                    resultMessage.append(QString("\nQuestion №%1: %2").arg(QString::number(index + 1), (question->quizIsCorrect) ? "✅" : "❌"));
                }

                resultMessage = resultMessage.arg(QString::number(correctAnswers), QString::number(MAX_QUIZ_QUESTIONS));

                QMessageBox msgBox;
                msgBox.setIcon(QMessageBox::Information);
                msgBox.setText(resultMessage);
                msgBox.exec();

                clearQuizData();
            }
        } else {
            clearQuizData();

            QMessageBox msgBox;
            msgBox.setIcon(QMessageBox::Critical);
            msgBox.setText("There was probably an error in processing the response from the AI. We have restarted the test, start again!");
            msgBox.exec();
        }
    } else {
        QMessageBox msgBox;
        msgBox.setIcon(QMessageBox::Critical);
        msgBox.setText("An error occurred when receiving a response from the AI: " + reply->errorString());
        msgBox.exec();
    }
}

void MainWindow::on_getQuestionButton_clicked()
{
    currentQuizQuestion++;
    ui->questionEdit->setText("Expect the AI to generate a question for you...");
    ui->getQuestionButton->setEnabled(false);

    sendPromptToAI(
        "Hi! Your task is to generate a maths problem. Tasks can be of different types "
        "- from simple examples to logic problems. Answer in JSON format only, "
        "without any additional text and markdown. Do not change value of \"type\" key in JSON. "
        "Value type of key \"answer\" should be always text (even if it's number). "
        "JSON: {\"type\": \"QUESTION_GENERATION\", \"question\": \"here_is_question\", \"answer\": \"here_is_answer\"}"
    );
}

void MainWindow::on_sendAnswerButton_clicked()
{
    Quiz *question = &quizQuestions[currentQuizQuestion];
    question->quizUserAnswer = ui->answerEdit->toPlainText();

    ui->sendAnswerButton->setEnabled(false);
    ui->questionEdit->setText("Waiting for the question verification result from AI...");
    ui->answerEdit->clear();

    sendPromptToAI(
        QString(
            "Hi. Your task is to answer whether the answer (userAnswer) is correct, "
            "compared to (correctAnswer) to a question (question). It is important to realize "
            "that the answer will not necessarily be physically identical. "
            "The user can add different explanations or any other unnecessary information. "
            "\n\nData: {\"questionId\": %1, \"question\": \"%2\", \"correctAnswer\": \"%3\", \"userAnswer\": \"%4\"}"
            "\n\nAnswer in JSON format only, without any additional text and markdown. Do not change value of \"type\" key in JSON. "
            "JSON: {\"type\": \"QUESTION_COMPARISON\", \"questionId\": %1, \"correct\": true/false}"
        ).arg(QString::number(currentQuizQuestion), question->quizQuestion, question->quizAIAnswer, question->quizUserAnswer)
    );
}

