#include "card.h"

Card::Card(const QString &name, const QString &author, const QString &recordType, const QString &libraryAddress, const QString &recordCreationDate)
{
    setName(name);
    setAuthor(author);
    setRecordType(recordType);
    setLibraryAddress(libraryAddress);
    setRecordCreationDate(recordCreationDate);
}

QString Card::getName() const
{
    return name;
}

void Card::setName(const QString &newName)
{
    name = newName;
}

QString Card::getAuthor() const
{
    return author;
}

void Card::setAuthor(const QString &newAuthor)
{
    author = newAuthor;
}

QString Card::getRecordType() const
{
    return recordType;
}

void Card::setRecordType(const QString &newRecordType)
{
    recordType = newRecordType;
}

QString Card::getLibraryAddress() const
{
    return libraryAddress;
}

void Card::setLibraryAddress(const QString &newLibraryAddress)
{
    libraryAddress = newLibraryAddress;
}

QString Card::getRecordCreationDate() const
{
    return recordCreationDate;
}

void Card::setRecordCreationDate(const QString &newRecordCreationDate)
{
    recordCreationDate = newRecordCreationDate;
}
