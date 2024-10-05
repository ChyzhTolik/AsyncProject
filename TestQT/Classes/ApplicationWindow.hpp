#ifndef APPLICATIONWINDOW_HPP
#define APPLICATIONWINDOW_HPP

#include <QObject>

class ApplicationWindow : public QObject
{
    Q_OBJECT
public:
    explicit ApplicationWindow(const QString& title, QObject *parent = nullptr);
    virtual ~ApplicationWindow();

signals:

private:
    QString m_title;
};

#endif // APPLICATIONWINDOW_HPP
