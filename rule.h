#ifndef RULE_H
#define RULE_H

#include <QString>
#include <QList>

class RulePeriod {
public:
    RulePeriod();

    int getStart() const;
    void setStart(int value);

    int getEnd() const;
    void setEnd(int value);

    float getValue() const;
    void setValue(float value);

private:
    int start;
    int end;
    float fvalue;
};

class RuleTrans {
public:
    RuleTrans();


    QString getFlowDam() const;
    void setFlowDam(const QString &value);

    float getRangeHiMaf() const;
    void setRangeHiMaf(float value);

    float getRangeLoMaf() const;
    void setRangeLoMaf(float value);

    float getRangeHi() const;
    void setRangeHi(float value);

    float getRangeLo() const;
    void setRangeLo(float value);

    float getMaxStart(int index);
    void setMaxStart(int index, float value);

    float getStartDate(int index);
    void setStartDate(int index, float value);

private:
    float startDate[3];
    float maxStart[3];
    float rangeLo;
    float rangeHi;
    float rangeLoMaf;
    float rangeHiMaf;
    QString flowDam;

};

class Rule
{
public:
    Rule();

    RuleTrans *getTrans();
    QList<RulePeriod *> *getPlannedSpillNight();
    QList<RulePeriod *> *getPlannedSpillDay();


    QString getProjectAbbv() const;
    void setProjectAbbv(const QString &value);

    QString getName() const;
    void setName(const QString &value);

private:
    RuleTrans trans;
    QList<RulePeriod *> plannedSpillNight;
    QList<RulePeriod *> plannedSpillDay;

    QString projectAbbv;
    QString name;

};

#endif // RULE_H
