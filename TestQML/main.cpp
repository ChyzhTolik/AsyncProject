#include <QCoreApplication>
#include "Userinteractor.hpp"

#include "Firefox.hpp"
#include "InternetExplorer.hpp"

int main(int argc, char* argv[])
{
    QCoreApplication a(argc,argv);

    UserInteractor interactor;
    Firefox firefox;
    InternetExplorer internetExplorer;

    QObject::connect(&interactor,&UserInteractor::phraseTyped, &firefox,&Firefox::browse);
    QObject::connect(&interactor,&UserInteractor::phraseTyped, &internetExplorer,&InternetExplorer::browseRequested);


    interactor.getInput();

    return a.exec();
}
