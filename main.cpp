#include "mainwindow.h"
#include "mainconsole.h"

#include <iostream>
#include <QCoreApplication>
#include <QApplication>
#include <qlogging.h>
#include "log.h"

int main(int argc, char *argv[])
{
    int retval = 0;
    if (MainConsole::consoleMode(argc, argv)) {
        qInstallMessageHandler(conMessageHandler);
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
            qInfo("Execution successful.");
        else
            qInfo("Execution stopped.");
    }
    else {
        QApplication a(argc, argv);
        MainWindow w;
        w.show();
        retval = a.exec();
    }

    return retval;
}
