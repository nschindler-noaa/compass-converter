#ifndef MAINCONSOLE_H
#define MAINCONSOLE_H

#include <QObject>
#include <QMultiMap>

#include "runsettings.h"
#include "yeardata.h"
#include "files.h"

class MainConsole : public QObject
{
    Q_OBJECT
public:
    explicit MainConsole(QObject *parent = nullptr);

public slots:
    int setup(RunSettings &sets);
    void setupProjects();
    void setupCmpProjects();
    int run(RunSettings &sets);
    int run();

    bool getInterrupt() const;
    void setInterrupt(bool value);

    static bool consoleMode (int argc, char *argv[]);

signals:
    void done(bool);

private:
    bool interrupt;
    RunSettings settings;
    YearData years;
    Files files;
    QList<Project *> projects;

};

#endif // MAINCONSOLE_H
