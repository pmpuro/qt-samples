#include "mypluginimpl.h"

#include <QtPlugin>

MyPluginImpl::MyPluginImpl(QObject *parent) :
    QObject(parent)
{
}

QString MyPluginImpl::getString() const
{
    return QString("Jes, tämä tuli itse plug-inista!");
}

Q_EXPORT_PLUGIN2(plugin_impl, MyPluginImpl)
