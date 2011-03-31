#ifndef MYLABEL_H
#define MYLABEL_H

#include <QLabel>
#include <QTimeLine>


class MyLabel : public QLabel
{
    Q_OBJECT
public:
    explicit MyLabel(QWidget *parent = 0);

    void keyPressEvent(QKeyEvent *ev);
    void paintEvent(QPaintEvent *);

signals:

public slots:
    void animateThis(qreal);

private:
    QColor color;
    QTimeLine timer;
    qreal factor;
};

#endif // MYLABEL_H
