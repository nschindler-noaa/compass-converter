#include <iostream>

#include <QApplication>

#include "mainconsole_old.h"
#include "files.h"

#define numYears (82)    // 1929 = 0
#define numPeriods (14)  // 10 Months plus AP1, AP2, SP1, SP2
#define numDays (366)    // Includes Feb 29th and Dec 31st of previous year (JAN01 repeated)

MainConsole::MainConsole()
 :  QObject()
{
    interrupt = !settings.setSettings(qApp->arguments());
    // get command line arguments and set settings
    if (!interrupt) {
        if (files.setupDirs(&settings)) {
            setupProjects();
        }
        else {
            std::cout << "Exiting due to file problem." << std::endl;
        }
    }
    else {
        std::cout << "Exiting due to problem with command arguments." << std::endl;
    }
}


int MainConsole::run() {
    int retval = 0;

    // if reading period values from file
    files.readData(&years);

    // modulate flow from period values to daily values
    if (settings.getDailyValues())
    {
//        run.modulateFlows(&files, &years);
    }

    // else read file(s) and populate daily values

    // if temperature generation required
    if (settings.getTempGenerate())
    {
//        run.generateTemps(&files, &years);
    }

    // produce COMPASS archive file to input flow/spill
//    files.createArchives(&files, &years);

    // create COMPASS .dat file
//    run.compassArchive(&files, &years);

    // create COMPASS .riv file
//    files.createRivYear(&years);

    // create COMPASS .trans file (if able)
//    files.createTrans(&years);

    // create COMPASS .rls file (if able)
//    files.createRelease(&years);

    // create COMPASS .scn file (incorporating all above)
//    run.compass(&files, &years);
    emit done(!interrupt);
    return retval;
}

bool MainConsole::getInterrupt() const
{
    return interrupt;
}

void MainConsole::setInterrupt(bool value)
{
    interrupt = value;
}

void MainConsole::setupProjects()
{

}

bool MainConsole::consoleMode (int argc, char *argv[])
{
    bool cmode = false;
    Q_UNUSED(argv);

    if (argc < 4)
        cmode = true;

    return cmode;
}


