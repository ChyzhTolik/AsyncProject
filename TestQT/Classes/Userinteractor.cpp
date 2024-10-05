#include "Userinteractor.hpp"

#include <QTextStream>
#include <QDebug>

UserInteractor::UserInteractor(QObject *parent)
    : QObject{parent}
{

}

void UserInteractor::getInput()
{
    qDebug()<<"\nType in your search phrase:\n";

    QTextStream s(stdin);
    const auto& phrase = s.readLine();

    if (!phrase.isEmpty())
    {
        setPhrase(phrase );
    }
}

QString UserInteractor::phrase() const
{
    return m_phrase;
}

void UserInteractor::setPhrase(const QString &phrase)
{
    if (m_phrase == phrase)
    {
        return;
    }

    m_phrase = phrase;
    emit phraseTyped(m_phrase);
}
