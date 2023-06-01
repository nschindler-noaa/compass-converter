#ifndef YEARDATA_H
#define YEARDATA_H

#include <QFile>

#include "project.h"
#include "meanvalues.h"
#include "periodvalues.h"

class YearData
{
public:
    YearData();
    ~YearData();

    int getYear() const;
    void setYear(int value);

    void clearData();
    void setupProjects(int days = 366);
    void setupMeans();
    void setupPeriods();

    project *findProject(int code);
    project *findProject(QString name);

private:
    int year;
    QList<project *> *projects;   // dams and pools
    QList<periodValues *> *rawData;  // monthly-period values
//    QList<periodValues *> *projects; // daily values
    QList<meanValues *>   *meanData; // historic mean values
};

#endif // YEARDATA_H
