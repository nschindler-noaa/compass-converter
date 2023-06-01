#ifndef RUNSETTINGS_H
#define RUNSETTINGS_H

#include <QStringList>

extern QString cmpssProjectsFile; // ("compass_projects.csv");
extern QString inputProjectsFile; // ("input_projects.csv");

enum Param {
    FLOW = 101,
    TEMP,
    SPILL,
    ALL,
    NOSPILL,
    MAF,
    NONE,
    CONST
};

class RunSettings
{
public:
    RunSettings();
    RunSettings(QStringList args);

    void setDefaults();
    bool setSettings(QStringList args);

    bool getDailyValues() const;
    void setDailyValues(bool value);

    QString getHydSimName() const;
    void setHydSimName(const QString &value);

    QString getInputFile() const;
    void setInputFile(const QString &value);

    QString getInputDir() const;
    void setInputDir(const QString &value);

    QString getAlterName() const;
    void setAlterName(const QString &value);

    QString getScenario() const;
    void setScenario(const QString &value);

    QString getRuleFile() const;
    void setRuleFile(const QString &value);

    QString getDailySpill() const;
    void setDailySpill(const QString &value);

    QString getDamParams() const;
    void setDamParams(const QString &value);

    QString getDataDir() const;
    void setDataDir(const QString &value);

    QString getOutputDir() const;
    void setOutputDir(const QString &value);

    Param getTrans() const;
    void setTrans(const Param &value);

    Param getMod() const;
    void setMod(const Param &value);

    Param getDebug() const;
    void setDebug(const Param &value);

    bool getTempGenerate() const;
    void setTempGenerate(bool value);

    QString getVersion();
    QString getHelp();
    QString getVerboseHelp();
    void printHelp(bool h, bool v);

    bool getOkay() const;
    void setOkay(bool value);

    bool getInterrupt() const;
    void setInterrupt(bool newInterrupt);

private:
    bool okay;
    bool interrupt;
    bool dailyValues;
    bool tempGenerate;
    QString inputProjectsFile;
    QString cmpssProjectsFile;
    QString currentDir;
    QString hydSimName;
    QString inputFile;
    QString inputDir;
    QString alterName;
    QString scenario;
    QString ruleFile;
    QString dailySpill;
    QString damParams;
    QString dataDir;
    QString outputDir;
    Param trans;
    Param mod;
    Param debug;

};

#endif // RUNSETTINGS_H
