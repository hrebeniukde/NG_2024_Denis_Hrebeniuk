#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QJsonObject>
#include <QJsonDocument>
#include <QMessageBox>

#define AI_GENERATE_POST_URL "http://127.0.0.1:11434/api/generate"
#define AI_MODEL_NAME "llama3.1:latest"

#define MAX_QUIZ_QUESTIONS 5

struct Quiz {
    QString quizQuestion;
    QString quizAIAnswer;
    QString quizUserAnswer;
    bool quizIsCorrect;
};

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_getQuestionButton_clicked();

    void on_sendAnswerButton_clicked();

    void aiAnswer(QNetworkReply *reply);

private:
    Ui::MainWindow *ui;

    QNetworkAccessManager *networkAccessManager;

    Quiz quizQuestions[MAX_QUIZ_QUESTIONS];

    int currentQuizQuestion;

    void sendPromptToAI(QString prompt);
    void clearQuizData();
};
#endif // MAINWINDOW_H
