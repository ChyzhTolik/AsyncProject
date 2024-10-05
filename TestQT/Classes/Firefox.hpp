#pragma once

#include <QObject>

class Firefox : public QObject
{
    Q_OBJECT
public:
    explicit Firefox(QObject *parent = nullptr);
public slots:
    void browse(const QString& phrase);
};
