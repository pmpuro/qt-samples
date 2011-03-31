#ifndef MYMODEL_H
#define MYMODEL_H

#include <QAbstractListModel>

class MyModel : public QAbstractListModel
{
    Q_OBJECT
public:
    explicit MyModel(QObject *parent = 0);

    int rowCount(const QModelIndex &parent) const;
    QVariant data(const QModelIndex &index, int role) const;

    Qt::ItemFlags flags(const QModelIndex &index) const;
    bool setData(const QModelIndex &index, const QVariant &value, int role);

signals:

public slots:

private:
    int noOfNumbers;
};

#endif // MYMODEL_H
