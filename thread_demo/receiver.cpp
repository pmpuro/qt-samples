#include "receiver.h"

Receiver::Receiver(QObject *parent) :
    QObject(parent)
{
}

void Receiver::theSlot()
{
    emit theSignal();
}
