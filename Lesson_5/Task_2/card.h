#ifndef CARD_H
#define CARD_H

#include <QString>

class Card
{
private:
    QString name;
    QString author;
    QString recordType;
    QString libraryAddress;
    QString recordCreationDate;

public:
    Card(const QString &name, const QString &author, const QString &recordType, const QString &libraryAddress, const QString &recordCreationDate);

    QString getName() const;
    void setName(const QString &newName);

    QString getAuthor() const;
    void setAuthor(const QString &newAuthor);

    QString getRecordType() const;
    void setRecordType(const QString &newRecordType);

    QString getLibraryAddress() const;
    void setLibraryAddress(const QString &newLibraryAddress);

    QString getRecordCreationDate() const;
    void setRecordCreationDate(const QString &newRecordCreationDate);

};

#endif // CARD_H
