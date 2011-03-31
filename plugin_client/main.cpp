#include <QApplication>
#include <QPushButton>
#include <QLabel>

#include <QPluginLoader>

#include "MyPlugin.h"

#include <QDebug>


int main(int argc, char* argv[])
{
    QApplication app(argc, argv);

    QLabel window;
    window.show();

    //app.addLibraryPath("/Users/pmp/code/Qt/plugin_impl-build-desktop");

    qDebug() << app.libraryPaths();

    QPluginLoader loader("/Users/pmp/code/Qt/plugin_impl-build-desktop/libplugin_impl.dylib");
    bool ok = loader.load();
    Q_ASSERT(ok);

    QObject* object = loader.instance();
    MyPlugin* plugin = qobject_cast<MyPlugin*>(object);

    if(plugin)
    {
        window.setText(plugin->getString());
    }

    return QApplication::exec();
}
