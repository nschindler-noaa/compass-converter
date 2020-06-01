#ifndef FILES_H
#define FILES_H



#include "runsettings.h"
#include "yeardata.h"

class Files
{
public:
    Files();

    bool setupDirs(RunSettings *set = nullptr);

    bool readData(YearData *yrs = nullptr);

    QString getApp() const;
    void setApp(const QString &value);

    QString getData() const;
    void setData(const QString &value);

    QString getUser() const;
    void setUser(const QString &value);

    QString getBin() const;
    void setBin(const QString &value);

    QString getMean() const;
    void setMean(const QString &value);

    QString getSub() const;
    void setSub(const QString &value);

    QString getFinal() const;
    void setFinal(const QString &value);

    QString getFlfcast() const;
    void setFlfcast(const QString &value);

    QString getTpfcast() const;
    void setTpfcast(const QString &value);

    QString getDat() const;
    void setDat(const QString &value);

    QString getFlarchive() const;
    void setFlarchive(const QString &value);

    QString getHydsim() const;
    void setHydsim(const QString &value);

    QString getHydro() const;
    void setHydro(const QString &value);

    QString getMonte() const;
    void setMonte(const QString &value);

    QString getPpData() const;
    void setPpData(const QString &value);

    QString getFmData() const;
    void setFmData(const QString &value);

private:
    QString app;        //
    QString data;
    QString user;       //
    QString bin;        //
    QString mean;       //
    QString sub;        //
    QString final;      //
    QString flfcast;    //
    QString tpfcast;    //
    QString dat;        //
    QString flarchive;  //
    QString hydsim;     //
    QString hydro;      //
    QString monte;      //
    QString ppData;
    QString fmData;

};

#endif // FILES_H
