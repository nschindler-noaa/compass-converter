#include <iostream>

#include <QCoreApplication>

#include "mainconsole.h"
#include "files.h"
#include "project.h"

#define numYears (82)    // 1929 = 0
#define numPeriods (14)  // 10 Months plus AP1, AP2, SP1, SP2
#define numDays (366)    // Includes Feb 29th and Dec 31st of previous year (JAN01 repeated)


MainConsole::MainConsole(QObject *parent) : QObject(parent)
{
    // get command line arguments and set settings
    interrupt = !settings.setSettings(qApp->arguments());
    if (!interrupt) {
        setup(settings);
    }
    else {
        if (!settings.getOkay()) {
            qCritical("Execution interrupted.");
            std::cout << "Execution interrupted." << std::endl;
        }
    }
}

int MainConsole::setup(RunSettings &sets)
{
    int retval = 0;
    if (files.setupDirs(&sets)) {
        setupProjects();
    }
    else {
        qCritical("Exiting due to a file problem.");
        std::cout << "Exiting due to a file problem." << std::endl;
        retval = -1;
    }
    return retval;
}

int MainConsole::run(RunSettings &sets)
{
    int retval = setup(sets);
    if (retval == 0)
        retval = run();
    else
        retval = -1;
    return retval;
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

void MainConsole::setupCmpProjects()
{

}

bool MainConsole::consoleMode (int argc, char *argv[])
{
    bool cmode = true;
    char *arg;

    if (argc < 4)
    {
        cmode = false;
        for (int i = 1; i < argc; i++) {
            arg = argv[i];
            if (arg[0] == '-')
                cmode = true;
        }
    }

    return cmode;
}

