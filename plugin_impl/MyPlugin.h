#ifndef MYPLUGIN_H
#define MYPLUGIN_H

#include <QString>
#include <QtPlugin>


class MyPlugin
{
public:
    virtual QString getString() const = 0;
};

Q_DECLARE_INTERFACE(MyPlugin, "org.oma.MyPlugin/1.0")

#endif // MYPLUGIN_H
