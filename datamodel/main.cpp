#include <QApplication>
#include <QListView>
#include <QTableView>

#include "mymodel.h"

int main(int argc, char* argv[])
{
    QApplication app(argc, argv);

    MyModel model;

    QListView view;
    view.setModel(&model);
    view.show();

    QTableView anotherView;
    anotherView.setModel(&model);
    anotherView.show();

    return QApplication::exec();
}
