#include <QSqlDriverPlugin>
#include <QSqlDriver>
#include <QPluginLoader>
#include <QDebug>

static QString dbDir = QString(PROJECT_SOURCE_DIR) + "/project_resource/db/PoemsSayings.db";

int main(int argc, char *argv[])
{
    QScopedPointer<QPluginLoader> pluginLoader(new QPluginLoader("sqldrivers/sqlitecipher_plugin.dll"));
    if (!pluginLoader->isLoaded())
    {
        qDebug() << "get plug instance failed: " << pluginLoader->errorString();
    }
    QObject* plugin = pluginLoader->instance();
    if (!plugin)
    {
        qDebug() << "get plug instance failed: " << pluginLoader->errorString();
        return -1;
    }
    QSqlDriverPlugin* driverPlugin = qobject_cast<QSqlDriverPlugin*>(plugin);
    if (!driverPlugin)
    {
        qDebug() << "qobject_cast to QSqlDriver* failed.";
        return -1;
    }

    QSqlDriver* driver = driverPlugin->create("SQLITECIPHER---");
    if (!driver)
    {
        qDebug() << "qobject_cast to QSqlDriver* failed.";
        return -1;
    }

    if (!driver->open(dbDir))
    {
        qDebug() << "qobject_cast to QSqlDriver* failed.";
        return -1;
    }
    

    return 0;
}