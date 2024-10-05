#include "testing.hpp"

#include "included_headers.hpp"

namespace Test
{
    void test_signals()
    {
        UserInteractor interactor;
        Firefox firefox;
        InternetExplorer internetExplorer;

        firefox.setProperty("version","2.12.12");

//        QObject::connect(&interactor,&UserInteractor::phraseTyped, &a,[&]
//                         {
//                             qDebug()<<interactor.property("phrase");
//                             qDebug()<<firefox.property("version");
//                         });

        interactor.getInput();
    }

    void test_windows()
    {
        ApplicationWindow rootWindow("Root Window");
        ApplicationWindow* parentWindow1 = new ApplicationWindow("Parent Window 1", &rootWindow);
        ApplicationWindow* parentWindow2 = new ApplicationWindow("Parent Window 2", &rootWindow);

        for (int var = 0; var < 2; ++var)
        {
            ApplicationWindow* childWindow1 =
                new ApplicationWindow(QString("Child widow %1 of Parent Window 1").arg(var), parentWindow1);
            ApplicationWindow* childWindow2 =
                new ApplicationWindow(QString("Child widow %1 of Parent Window 2").arg(var), parentWindow1);
        }
    }

} // namespace Test
