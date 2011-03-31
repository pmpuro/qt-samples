#ifndef MYPLUGINIMPL_H
#define MYPLUGINIMPL_H

#include <QtPlugin>
#include "myplugin.h"


class MyPluginImpl : public QObject, public MyPlugin {
    Q_OBJECT
    Q_INTERFACES(MyPlugin)
public:
    MyPluginImpl(QObject *parent = 0);

    QString getString() const;
};

#endif // MYPLUGINIMPL_H
