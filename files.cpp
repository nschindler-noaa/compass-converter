#include "files.h"

Files::Files()
{

}

bool Files::setupDirs(RunSettings *set)
{
    bool okay = true;
    if (set == nullptr) {
        okay = false;
    } else {
        // input directory
        if (!set->getInputDir().isEmpty())
            inputDir = QDir(set->getInputDir());
        else
            okay = false;
        // output directory

        // other (intermediate directories)
    }

    return okay;
}

bool Files::readData(YearData *yrs)
{
    bool okay = true;
    if (yrs == nullptr) {
        okay = false;
    }
    else {
        // what kinda file is it?

    }

    return okay;
}

QString Files::getApp() const
{
    return app;
}

void Files::setApp(const QString &value)
{
    app = value;
}

QString Files::getData() const
{
    return data;
}

void Files::setData(const QString &value)
{
    data = value;
}

QString Files::getUser() const
{
    return user;
}

void Files::setUser(const QString &value)
{
    user = value;
}

QString Files::getBin() const
{
    return bin;
}

void Files::setBin(const QString &value)
{
    bin = value;
}

QString Files::getMean() const
{
    return mean;
}

void Files::setMean(const QString &value)
{
    mean = value;
}

QString Files::getSub() const
{
    return sub;
}

void Files::setSub(const QString &value)
{
    sub = value;
}

QString Files::getFinal() const
{
    return final;
}

void Files::setFinal(const QString &value)
{
    final = value;
}

QString Files::getFlfcast() const
{
    return flfcast;
}

void Files::setFlfcast(const QString &value)
{
    flfcast = value;
}

QString Files::getTpfcast() const
{
    return tpfcast;
}

void Files::setTpfcast(const QString &value)
{
    tpfcast = value;
}

QString Files::getDat() const
{
    return dat;
}

void Files::setDat(const QString &value)
{
    dat = value;
}

QString Files::getFlarchive() const
{
    return flarchive;
}

void Files::setFlarchive(const QString &value)
{
    flarchive = value;
}

QString Files::getHydsim() const
{
    return hydsim;
}

void Files::setHydsim(const QString &value)
{
    hydsim = value;
}

QString Files::getHydro() const
{
    return hydro;
}

void Files::setHydro(const QString &value)
{
    hydro = value;
}

QString Files::getMonte() const
{
    return monte;
}

void Files::setMonte(const QString &value)
{
    monte = value;
}

QString Files::getPpData() const
{
    return ppData;
}

void Files::setPpData(const QString &value)
{
    ppData = value;
}

QString Files::getFmData() const
{
    return fmData;
}

void Files::setFmData(const QString &value)
{
    fmData = value;
}
