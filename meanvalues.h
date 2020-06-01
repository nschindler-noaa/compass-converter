#ifndef MEANVALUES_H
#define MEANVALUES_H

#include <QVector>

class meanValues
{
public:
    meanValues(int size);

    int getCode() const;
    void setCode(int value);

    float getFlow(int index) const;
    void setFlow(int index, const float &value);

    float getTemp(int index) const;
    void setTemp(int index, const float &value);

private:
    int code;
    QVector<float> flow;
    QVector<float> temp;
};

#endif // MEANVALUES_H
