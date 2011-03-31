#ifndef MYFILTER_H
#define MYFILTER_H

#include <QObject>

class MyFilter : public QObject
{
    Q_OBJECT
public:
    explicit MyFilter(QObject *parent = 0);

    bool eventFilter(QObject *, QEvent *);

signals:

public slots:

};

#endif // MYFILTER_H
