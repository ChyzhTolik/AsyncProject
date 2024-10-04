#pragma once

#include <QObject>

class UserInteractor : public QObject
{
    Q_OBJECT
public:
    explicit UserInteractor(QObject *parent = nullptr);

    void getInput();
signals:
    void phraseTyped(const QString& phrase);
};
