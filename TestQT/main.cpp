#include <QCoreApplication>

#include "testing.hpp"
#include "included_headers.hpp"
#include <QTimer>

int main(int argc, char* argv[])
{
    QCoreApplication a(argc,argv);

//    Test::test_windows();

    UserInteractor interactor;
    Firefox firefox;
    InternetExplorer internetExplorer;

    firefox.setProperty("version","2.12.12");

    QObject::connect(&interactor,&UserInteractor::phraseTyped, &a,[&]
                     {
        qDebug()<<interactor.property("phrase");
        qDebug()<<firefox.property("version");
    });

    interactor.getInput();
    

    return a.exec();
}
