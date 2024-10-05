#ifndef INTERNETEXPLORER_HPP
#define INTERNETEXPLORER_HPP

#include <QObject>
#include <QTimer>

class InternetExplorer : public QObject
{
    Q_OBJECT
public:
    explicit InternetExplorer(QObject *parent = nullptr);

public slots:
    void browse();

signals:
    void browseRequested(const QString& phrase);

private:
    QTimer m_timer;
};

#endif // INTERNETEXPLORER_HPP
