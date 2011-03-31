#ifndef MYCOUNTER_H
#define MYCOUNTER_H

#include <QObject>

class MyCounter : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int currentValue READ value NOTIFY currentValueChanged)
public:
    explicit MyCounter(QObject *parent = 0);

    int value() const;

signals:
    void currentValueChanged();
    void reached10(int value);

public slots:
    void increase();

private:
    int counter;
};

#endif // MYCOUNTER_H
