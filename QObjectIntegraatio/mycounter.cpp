#include "mycounter.h"

MyCounter::MyCounter(QObject *parent) :
    QObject(parent), counter(1)
{
}

int MyCounter::value() const
{
    return counter;
}

void MyCounter::increase()
{
    ++counter;

    emit currentValueChanged();

    if(0 == counter%10){
        emit reached10(value());
    }
}
