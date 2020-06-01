#include "meanvalues.h"

meanValues::meanValues(int size)
{
    code = 0;
    for (int i = 0; i < size; i++) {
        flow.append(0);
        temp.append(0);
    }
}

int meanValues::getCode() const
{
    return code;
}

void meanValues::setCode(int value)
{
    code = value;
}

float meanValues::getFlow(int index) const
{
    return flow[index];
}

void meanValues::setFlow(int index, const float &value)
{
    flow[index] = value;
}

float meanValues::getTemp(int index) const
{
    return temp[index];
}

void meanValues::setTemp(int index, const float &value)
{
    temp[index] = value;
}
