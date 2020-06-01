#include "rule.h"

RulePeriod::RulePeriod()
{
    start = 0;
    end = 366;
    fvalue = 0;
}

int RulePeriod::getStart() const
{
    return start;
}
void RulePeriod::setStart(int value)
{
    start = value;
}

int RulePeriod::getEnd() const
{
    return end;
}
void RulePeriod::setEnd(int value)
{
    end = value;
}

float RulePeriod::getValue() const
{
    return fvalue;
}
void RulePeriod::setValue(float value)
{
    fvalue = value;
}



RuleTrans::RuleTrans()
{
    for (int i = 0; i < 3; i++) {
        startDate[i] = 0;
        maxStart[i] = 0;
    }
    rangeLo = 0;
    rangeHi = 10;
    rangeLoMaf = 0;
    rangeHiMaf = 10;
    flowDam = QString("");
}

QString RuleTrans::getFlowDam() const
{
    return flowDam;
}

void RuleTrans::setFlowDam(const QString &value)
{
    flowDam = value;
}

float RuleTrans::getRangeHiMaf() const
{
    return rangeHiMaf;
}

void RuleTrans::setRangeHiMaf(float value)
{
    rangeHiMaf = value;
}

float RuleTrans::getRangeLoMaf() const
{
    return rangeLoMaf;
}

void RuleTrans::setRangeLoMaf(float value)
{
    rangeLoMaf = value;
}

float RuleTrans::getRangeHi() const
{
    return rangeHi;
}

void RuleTrans::setRangeHi(float value)
{
    rangeHi = value;
}

float RuleTrans::getRangeLo() const
{
    return rangeLo;
}

void RuleTrans::setRangeLo(float value)
{
    rangeLo = value;
}

float RuleTrans::getMaxStart(int index)
{
    return maxStart[index];
}

void RuleTrans::setMaxStart(int index, float value)
{
    maxStart[index] = value;
}

float RuleTrans::getStartDate(int index)
{
    return startDate[index];
}

void RuleTrans::setStartDate(int index, float value)
{
    startDate[index] = value;
}

Rule::Rule()
{

}

RuleTrans *Rule::getTrans()
{
    return &trans;
}
QList<RulePeriod *> *Rule::getPlannedSpillNight()
{
    return &plannedSpillNight;
}
QList<RulePeriod *> *Rule::getPlannedSpillDay()
{
    return &plannedSpillDay;
}

QString Rule::getProjectAbbv() const
{
    return projectAbbv;
}

void Rule::setProjectAbbv(const QString &value)
{
    projectAbbv = value;
}

QString Rule::getName() const
{
    return name;
}

void Rule::setName(const QString &value)
{
    name = value;
}


