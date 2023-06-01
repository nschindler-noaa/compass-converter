#include "yeardata.h"

YearData::YearData()
{
    rawData = new QList<periodValues *>();
    projects = new QList<project *>();
    meanData = new QList<meanValues *>();

    setupMeans();
    setupPeriods();
    setupProjects();
}

YearData::~YearData()
{
    clearData();
}

void YearData::clearData()
{
    while (rawData->count() > 0)
    {
        periodValues *n = rawData->takeLast();
        delete n;
    }
    while (projects->count() > 0)
    {
        project *p = projects->takeLast();
        delete p;
    }
    while (meanData->count() > 0)
    {
        meanValues *m = meanData->takeLast();
        delete m;
    }
}

int YearData::getYear() const
{
    return year;
}

void YearData::setYear(int value)
{
    year = value;
}

void YearData::setupMeans()
{

}

void YearData::setupPeriods()
{

}

void YearData::setupProjects(int days)
{

}

project *YearData::findProject(int code)
{
    int index = 0;
    for (index = 0; index < projects->count(); index++)
    {
        if (projects->at(index)->getCode() == code)
            break;
    }
    return projects->at(index);
}

project *YearData::findProject(QString name)
{
    int index = 0;
    for (index = 0; index < projects->count(); index++)
    {
        if (projects->at(index)->getName() == name)
            break;
    }
    return projects->at(index);
}

