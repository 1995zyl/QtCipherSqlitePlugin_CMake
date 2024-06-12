#include "test_sqlite3mc.h"
#include <QSqlDriverPlugin>
#include <QSqlDriver>
#include <QPluginLoader>
#include <QDebug>

const static QString dbDir("test.db");
static bool LoadSqlDriver(QSqlDriver* driver)
{
    QScopedPointer<QPluginLoader> pluginLoader(new QPluginLoader("sqldrivers/sqlitecipherd.dll"));
    if (!pluginLoader->isLoaded())
    {
        qDebug() << "get plug instance failed: " << pluginLoader->errorString();
    }

    QObject* plugin = pluginLoader->instance();
    if (!plugin)
    {
        qDebug() << "get plug instance failed: " << pluginLoader->errorString();
        return false;
    }

    QSqlDriverPlugin* driverPlugin = qobject_cast<QSqlDriverPlugin*>(plugin);
    if (!driverPlugin)
    {
        qDebug() << "qobject_cast to QSqlDriver* failed.";
        return false;
    }

    driver = driverPlugin->create("SQLITECIPHER");
    if (!driver)
    {
        qDebug() << "qobject_cast to QSqlDriver* failed.";
        return false;
    }

    return true;
}

Sqlite3mcBaseTest::Sqlite3mcBaseTest()
{

}

Sqlite3mcEncryptionTest::Sqlite3mcEncryptionTest()
{
    
}