#include "tekstinmuuttaja.h"

#include <QObject>
#include <QVariant>


TekstinMuuttaja::TekstinMuuttaja(QObject* nappi, QObject *parent) :
    QObject(parent), muutettavaNappi(nappi)
{
}

void TekstinMuuttaja::muutaTeksti()
{
    muutettavaNappi->setProperty("text", QVariant(QString("Jep, toki")));
}
