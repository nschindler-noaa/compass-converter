#include "yeardata.h"

YearData::YearData()
{
    rawData = new QList<periodValues *>();
    projects = new QList<periodValues *>();
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
        periodValues *p = projects->takeLast();
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

void YearData::setupProjects()
{

}

