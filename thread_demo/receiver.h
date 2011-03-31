#ifndef RECEIVER_H
#define RECEIVER_H

#include <QObject>

class Receiver : public QObject
{
    Q_OBJECT
public:
    explicit Receiver(QObject *parent = 0);

signals:
    void theSignal();

public slots:
    void theSlot();
};

#endif // RECEIVER_H
