#include "runsettings.h"
#include "log.h"

#include <QDir>

#include <iostream>


RunSettings::RunSettings()
{
    setDefaults();
}

RunSettings::RunSettings(QStringList args)
{
    setDefaults();
    setSettings(args);
}

void RunSettings::setDefaults()
{
    cmpssProjectsFile = QString("/pre-proc/compass_projects.csv");
    inputProjectsFile = QString("/pre-proc/input_projects.csv");
    okay = true;
    currentDir = QDir::current().path();
    setHydSimName(QString(""));
    setInputDir(QString(currentDir + QString("/pre-proc")));
    setInputFile(QString(""));
    setAlterName(QString(""));
    setScenario(QString(""));
    setRuleFile(QString(currentDir + QString("/pre-proc/preProcData/Rules.pm")));
    setDailyValues(false);
    setDamParams(QString(currentDir + QString("/pre-proc/damParams")));
    setDataDir(QString(currentDir + QString("/pre-proc")));
    setOutputDir(QString(currentDir + QString("/pre-proc")));
    setMod(NOSPILL);
    setDebug(ALL);
    setTrans(MAF);
}

QString RunSettings::getVersion()
{
    QString ver("COMPASS Pre-processor version 2.0");
    return ver;
}

// Usage ====================================================================
QString RunSettings::getHelp()
{
    QString use ("compass_pp -alt=ALT_NAME -hydro=HYDSIM_DIR -scenario=SCN_NAME \n");
    use.append ("    [ -rules=RULE_FILE_NAME ] [ -hydsim=HYDSIM_PRT [-d] ] [ -spill=DAY_SPILL ]\n");
    use.append ("    [ -dam=DAM_PARAMS ] [ -mod=ALL|NOSPILL ] [ -trans=MAF|FLOW|TEMP ]\n");
    use.append ("    [ -debug=TEMP|SPILL|ALL ] [ -data=DATA_DIR ] [ -out=OUTPUT_DIR ] [ -help ]\n");
    return use;
}

// Verbose ==================================================================
QString RunSettings::getVerboseHelp ()
{
    //Required===================================================================
    QString verbose ("=Required================\n");
    verbose.append ("    ALT_NAME     Alternative used in the Rules.pm module to specify spill and\n");
    verbose.append ("                 other operations. No spaces allowed in name.\n");
    verbose.append ("                   example: -alt=base2004-S1\n\n");

    verbose.append ("    HYDSIM_DIR   If no HYDSIM_PRT file, then HYDSIM model files (.csv), must\n ");
    verbose.append ("                 reside in the directory DATA_DIR/'HydSim'/HYDSIM_NAME. \n");
    verbose.append ("                 No spaces allowed in name.\n");
    verbose.append ("                   example: -hydsim=base2004\n\n");

    verbose.append ("    SCN_NAME     Unique name used to identify the scenario and to archive\n");
    verbose.append ("                 intermediate and final files from the run.\n");
    verbose.append ("                 No spaces allowed in name.\n");
    verbose.append ("                   example: -scenario=base2004-S1\n\n");

    //Optional===================================================================
    verbose.append ("=Optional=================\n");
    verbose.append ("    RULE_FILE_NAME The fully qualified file name for Rules.pm which includes\n");
    verbose.append ("                 the ALT_NAME.\n");
    verbose.append ("                    example: -rules=C:/data/pre-proc/PreProcData/Rules.pm\n\n");

    verbose.append ("    HYDSIM_PRT   The fully qualified file name for HYDSIM output, by month or \n");
    verbose.append ("                 day. If this is not used, the program assumes that the daily\n");
    verbose.append ("                 flow modulated file(s) reside in the HydSim/HYDSIM_NAME\n");
    verbose.append ("                 directory. No spaces allowed in name.\n");
    verbose.append ("                    example: -hydro=C:/data/HydSim/PImotionSpill&Res+plus.PRT\n\n");
    verbose.append ("    -d           Signifies the HYDSIM output is in daily values. Not implemented\n\n");

    verbose.append ("    DAY_SPILL    The fully qualified file name for HYDSIM daily spill fraction \n");
    verbose.append ("                 in each month. If this is not specified, the program uses a \n");
    verbose.append ("                 default file. Only used if HYDSIM_PRT is specified.\n");
    verbose.append ("                 No spaces allowed in name.\n");
    verbose.append ("                    example: -spill=PImotion_in_month_spill_2008_12.csv\n\n");

    verbose.append ("    DAM_PARAMS   Name of the dam parameters to use. This is the unique\n");
    verbose.append ("                 part of the files in the 'damParams' directory. if not provided,\n");
    verbose.append ("                 damParams is not completed. No spaces allowed in name.\n");
    verbose.append ("                    example: -dam=2004_Base\n\n");

    verbose.append ("    mod          Flag to indicate that HYDSIM flow, spill, elev in single\n");
    verbose.append ("                 file with daily modulated flow, monthly spills, seasonal\n");
    verbose.append ("                 elevation. The default is NOSPILL. \n");
    verbose.append ("                  -mod=ALL     use all inputs (default)\n");
    verbose.append ("                  -mod=NOSPILL use only flow input\n\n");

    verbose.append ("    trans        Flag to indicate what determines transport dates. The\n");
    verbose.append ("                 default is MAF. \n");
    verbose.append ("                  -trans=MAF   turns on option to set transport based on\n");
    verbose.append ("                        reverse engineering of spill to get MAF forecast.\n");
    verbose.append ("                  -trans=FLOW  turns on option to modify spill operations\n");
    verbose.append ("                        based on spring averaged flow levels and sets \n");
    verbose.append ("                        transport start dates.\n");
    verbose.append ("                  -trans=TEMP  turns on option to modify spill operations\n");
    verbose.append ("                        based on spring temperatures and sets transport\n");
    verbose.append ("                        start dates.\n\n");

    verbose.append ("    debug        Outputs additional parameters from COMPASS runs for\n");
    verbose.append ("                 examining temperature and other modelled parameters.\n");
    verbose.append ("                  -debug=TEMP  outputs temperature and flow values.\n");
    verbose.append ("                  -debug=SPILL outputs spill values.\n");
    verbose.append ("                  -debug=ALL   outputs temperature, flow, spill values.\n\n");

    verbose.append ("    DATA_DIR     Directory that holds necessary data files. If not given,\n");
    verbose.append ("                 default is \"pre-proc\". No spaces allowed in name and use\n");
    verbose.append ("                 forward slash as separator ('/').\n");
    verbose.append ("                    example: -data=C:/data/pre-proc\n\n");

    verbose.append ("    OUTPUT_DIR   Output directory. If not given, output files will be in\n");
    verbose.append ("                 default directory. No spaces allowed in name and use\n");
    verbose.append ("                 forward slash as separator ('/').\n");
    verbose.append ("                    example: -output=C:/out/Final/MOD/debug1\n\n");

    verbose.append ("    help         Prints this information (-help).\n\n");

    return verbose;
}

void RunSettings::printHelp(bool h, bool v) {
    Log::logMessage(NORML, getVersion());
//    std::cout << getVersion().toUtf8().data();
    if (h) {
        Log::logMessage(NORML, getHelp());
//        std::cout << getHelp().toUtf8().data();
        if (v)
            Log::logMessage(NORML, getVerboseHelp());
//            std::cout << getVerboseHelp().toUtf8().data();
    }
}

bool RunSettings::getOkay() const
{
    return okay;
}

void RunSettings::setOkay(bool value)
{
    okay = value;
}

bool RunSettings::setSettings(QStringList args)
{
    okay = true;
    bool interrupt = false;
    bool version = false;
    bool help = false;
    QString arg;
    QStringList part;
    for (int i = 1; i < args.count(); i++)
    {
        arg = QString(args.at(i));
        part = arg.split('=');
        if  (part.at(0).startsWith("-alt", Qt::CaseInsensitive)) {
            setAlterName(part.at(1));
        }
        else if (part.at(0).startsWith("-hydro", Qt::CaseInsensitive)) {
            setHydSimName(part.at(1));
        }
        else if (part.at(0).startsWith("-scenario", Qt::CaseInsensitive)) {
            setScenario(part.at(1));
        }
        else if (part.at(0).startsWith("-rules")) {
            setRuleFile(part.at(1));
        }
        else if (part.at(0).startsWith("-hydsim", Qt::CaseInsensitive)) {
            setInputFile(part.at(1));
            setInputDir(part.at(1));
        }
        else if (part.at(0).startsWith("-d", Qt::CaseInsensitive)) {
            setDailyValues(true);
        }
        else if (part.at(0).startsWith("-spill", Qt::CaseInsensitive)) {
            setDailySpill(part.at(1));
        }
        else if (part.at(0).startsWith("-dam", Qt::CaseInsensitive)) {
            setDamParams(part.at(1));
        }
        else if (part.at(0).startsWith("-data", Qt::CaseInsensitive)) {
            setDataDir(part.at(1));
        }
        else if (part.at(0).startsWith("-out", Qt::CaseInsensitive)) {
            setOutputDir(part.at(1));
        }
        else if (part.at(0).startsWith("-trans", Qt::CaseInsensitive)) {
            if (part.at(1).contains("MAF", Qt::CaseInsensitive) == 0)
                setTrans(MAF);
            else if (part.at(1).contains("FLOW", Qt::CaseInsensitive) == 0)
                setTrans(FLOW);
            else if (part.at(1).contains("TEMP", Qt::CaseInsensitive) == 0)
                setTrans(TEMP);
        }
        else if (part.at(0).startsWith("-mod", Qt::CaseInsensitive)) {
            if (part.at(1).contains("ALL", Qt::CaseInsensitive) == 0)
                setTrans(ALL);
            else if (part.at(1).contains("NOSPILL", Qt::CaseInsensitive) == 0)
                setTrans(NOSPILL);
        }
        else if (part.at(0).startsWith("-debug", Qt::CaseInsensitive)) {
            if (part.at(1).contains("TEMP", Qt::CaseInsensitive) == 0)
                setTrans(TEMP);
            else if (part.at(1).contains("SPILL", Qt::CaseInsensitive) == 0)
                setTrans(SPILL);
            else if (part.at(1).contains("ALL", Qt::CaseInsensitive) == 0)
                setTrans(ALL);
        }
        else if (part.at(0).contains("-h", Qt::CaseInsensitive)) {
            help = true;
        }
        else if (part.at(0).contains("-v", Qt::CaseInsensitive)) {
            version = true;
        }
    }
    if (help || version) {
        interrupt = true;
        printHelp(help, version);
    }

    return !interrupt;
}

bool RunSettings::getDailyValues() const
{
    return dailyValues;
}

void RunSettings::setDailyValues(bool value)
{
    dailyValues = value;
}

QString RunSettings::getHydSimName() const
{
    return hydSimName;
}

void RunSettings::setHydSimName(const QString &value)
{
    hydSimName = value;
}

QString RunSettings::getInputFile() const
{
    return inputFile;
}

void RunSettings::setInputFile(const QString &value)
{
    inputFile = value;
}

QString RunSettings::getInputDir() const
{
    return inputDir;
}

void RunSettings::setInputDir(const QString &value)
{
    inputDir = value;
}

QString RunSettings::getAlterName() const
{
    return alterName;
}

void RunSettings::setAlterName(const QString &value)
{
    alterName = value;
}

QString RunSettings::getScenario() const
{
    return scenario;
}

void RunSettings::setScenario(const QString &value)
{
    scenario = value;
}

QString RunSettings::getRuleFile() const
{
    return ruleFile;
}

void RunSettings::setRuleFile(const QString &value)
{
    ruleFile = value;
}

QString RunSettings::getDailySpill() const
{
    return dailySpill;
}

void RunSettings::setDailySpill(const QString &value)
{
    dailySpill = value;
}

QString RunSettings::getDamParams() const
{
    return damParams;
}

void RunSettings::setDamParams(const QString &value)
{
    damParams = value;
}

QString RunSettings::getDataDir() const
{
    return dataDir;
}

void RunSettings::setDataDir(const QString &value)
{
    dataDir = value;
}

QString RunSettings::getOutputDir() const
{
    return outputDir;
}

void RunSettings::setOutputDir(const QString &value)
{
    outputDir = value;
}

Param RunSettings::getTrans() const
{
    return trans;
}

void RunSettings::setTrans(const Param &value)
{
    trans = value;
}

Param RunSettings::getMod() const
{
    return mod;
}

void RunSettings::setMod(const Param &value)
{
    mod = value;
}

Param RunSettings::getDebug() const
{
    return debug;
}

void RunSettings::setDebug(const Param &value)
{
    debug = value;
}

bool RunSettings::getTempGenerate() const
{
    return tempGenerate;
}

void RunSettings::setTempGenerate(bool value)
{
    tempGenerate = value;
}
