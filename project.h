#ifndef PROJECT_H
#define PROJECT_H

#include <QVector>
#include <QStringList>
#include <QMultiMap>

class Project
{
public:
    Project(int cd = 0, QString nm=QString(), QString ab=QString());
    ~Project();
    void clear();
    void allocate(int days = 366);

    int getCode() const;
    void setCode(int newCode);

    const QString &getName() const;
    void setName(const QString &newName);

    const QString &getAbbv() const;
    void setAbbv(const QString &newAbbv);

    const float &getFlow(int index) const;
    void setFlow(int index, const float &newFlow);

    const float &getSpill(int index) const;
    void setSpill(int index, const float &newSpill);

    const float &getSpillPct(int index) const;
    void setSpillPct(int index, const float &newSpillPct);

    const float &getOverGen(int index) const;
    void setOverGen(int index, const float &newOverGen);

    const float &getTemp(int index) const;
    void setTemp(int index, const float &newTemp);

    const float &getElevForebay(int index) const;
    void setElevForebay(int index, const float &newElevForebay);

    const float &getElevTailrace(int index) const;
    void setElevTailrace(int index, const float &newElevTailrace);

private:
    int code;
    QString name;
    QString abbv;
    QVector<float> flow;
    QVector<float> spill;
    QVector<float> spillPct;
    QVector<float> overGen;
    QVector<float> temp;
    QVector<float> elevForebay;
    QVector<float> elevTailrace;
};

#endif // PROJECT_H
