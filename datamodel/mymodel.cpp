#include "mymodel.h"

MyModel::MyModel(QObject *parent) :
    QAbstractListModel(parent),
    noOfNumbers(3)
{
}

int MyModel::rowCount(const QModelIndex &) const
{
    return 1 + noOfNumbers;
}

static int fibo(int nth)
{
    int previous = 1;
    int before_previous = 0;

    for(int i = 2; i < nth; ++i)
    {
        int temp = before_previous;
        before_previous = previous;
        previous = temp + previous;
    }

    const int result = before_previous + previous;

    return result;
}

QVariant MyModel::data(const QModelIndex &index, int role) const
{
    if(Qt::DisplayRole == role)
    {
        if(0 == index.row())
        {
            return QVariant(noOfNumbers);
        } else
        {
            const int number = fibo(index.row());
            return QVariant(number);
        }
    }

    return QVariant();
}


Qt::ItemFlags MyModel::flags(const QModelIndex &index) const
{
    Qt::ItemFlags result = QAbstractListModel::flags(index);

    if(0 == index.row())
    {
        result |= Qt::ItemIsEditable;
    }

    return result;
}

bool MyModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if(0 == index.row() && Qt::EditRole == role)
    {
        bool ok = false;
        const int newValue = value.toInt(&ok);

        if(ok)
        {
            noOfNumbers = newValue;
            reset();
            return true;
        }
    }

    return false;
}
