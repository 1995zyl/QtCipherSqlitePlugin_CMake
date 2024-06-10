#include "sqlitecipher_p.h"
#include "smain.h"

QT_BEGIN_NAMESPACE

static const char DriverName[] = "SQLITECIPHER";

SqliteCipherDriverPlugin::SqliteCipherDriverPlugin()
    : QSqlDriverPlugin()
{
}

SqliteCipherDriverPlugin::~SqliteCipherDriverPlugin()
{
}

QSqlDriver *SqliteCipherDriverPlugin::create(const QString &name)
{
    if (name == QLatin1String("SQLITECIPHER"))
    {
        SQLiteCipherDriver *driver = new SQLiteCipherDriver();
        return driver;
    }

    return nullptr;
}

QT_END_NAMESPACE
