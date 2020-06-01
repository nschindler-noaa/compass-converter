#include "mainwindow.h"
#include "mainconsole.h"

#include <iostream>
#include <QApplication>
#include <QCoreApplication>

int main(int argc, char *argv[])
{
    int retval = 0;
    if (MainConsole::consoleMode(argc, argv)) {
        QCoreApplication a(argc, argv);
        MainConsole c;
        if (c.getInterrupt()) {
            retval = 1;
        }
        else {
            QObject::connect(&c, SIGNAL(done(bool)),
                             &a, SLOT(quit()), Qt::QueuedConnection);
            c.run();
            retval = a.exec();
        }
        if (retval == 0)
            std::cout << "Execution successful." << std::endl;
        else
            std::cout << "Execution stopped." << std::endl;
    }
    else {
        QApplication a(argc, argv);
        MainWindow w;
        w.show();
        retval = a.exec();
    }

    return retval;
}
