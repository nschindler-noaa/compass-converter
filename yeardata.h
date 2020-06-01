#ifndef YEARDATA_H
#define YEARDATA_H

#include <QFile>

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
    void setupProjects();
    void setupMeans();
    void setupPeriods();

private:
    int year;
    QList<periodValues *> *rawData;  // monthly-period values
    QList<periodValues *> *projects; // daily values
    QList<meanValues *>   *meanData; // historic mean values
};

#endif // YEARDATA_H
