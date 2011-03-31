#ifndef TEKSTINMUUTTAJA_H
#define TEKSTINMUUTTAJA_H

#include <QObject>

class TekstinMuuttaja : public QObject
{
    Q_OBJECT
public:
    explicit TekstinMuuttaja(QObject*nappi, QObject *parent = 0);

signals:

public slots:
    void muutaTeksti();

private:
    QObject* muutettavaNappi;
};

#endif // TEKSTINMUUTTAJA_H
