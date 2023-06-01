#include "project.h"

Project::Project(int cd, QString nm, QString ab)
{
    clear();
    code = cd;
    name = QString(nm);
    abbv = QString(ab);
}

Project::~Project()
{
    name.clear();
    abbv.clear();
    clear();
}

void Project::clear()
{
    flow.clear();
    spill.clear();
    spillPct.clear();
    overGen.clear();
    temp.clear();
    elevForebay.clear();
    elevTailrace.clear();
}

void Project::allocate(int days)
{
    clear();
    for (int i = 0; i < days; i++)
    {
        flow.append(0);
        spill.append(0);
        spillPct.append(0);
        overGen.append(0);
        temp.append(0);
        elevForebay.append(0);
        elevTailrace.append(0);
    }
}

int Project::getCode() const
{
    return code;
}

void Project::setCode(int newCode)
{
    code = newCode;
}

const QString &Project::getName() const
{
    return name;
}

void Project::setName(const QString &newName)
{
    name = newName;
}

const QString &Project::getAbbv() const
{
    return abbv;
}

void Project::setAbbv(const QString &newAbbv)
{
    abbv = newAbbv;
}

const float &Project::getFlow(int index) const
{
    return flow[index];
}

void Project::setFlow(int index, const float &newFlow)
{
    flow[index] = newFlow;
}

const float &Project::getSpill(int index) const
{
    return spill[index];
}

void Project::setSpill(int index, const float &newSpill)
{
    spill[index] = newSpill;
}

const float &Project::getSpillPct(int index) const
{
    return spillPct[index];
}

void Project::setSpillPct(int index, const float &newSpillPct)
{
    spillPct[index] = newSpillPct;
}

const float &Project::getOverGen(int index) const
{
    return overGen[index];
}

void Project::setOverGen(int index, const float &newOverGen)
{
    overGen[index] = newOverGen;
}

const float &Project::getTemp(int index) const
{
    return temp[index];
}

void Project::setTemp(int index, const float &newTemp)
{
    temp[index] = newTemp;
}

const float &Project::getElevForebay(int index) const
{
    return elevForebay[index];
}

void Project::setElevForebay(int index, const float &newElevForebay)
{
    elevForebay[index] = newElevForebay;
}

const float &Project::getElevTailrace(int index) const
{
    return elevTailrace[index];
}

void Project::setElevTailrace(int index, const float &newElevTailrace)
{
    elevTailrace[index] = newElevTailrace;
}
