#ifndef SMAIN_H
#define SMAIN_H

#include <QSqlDriverPlugin>

QT_BEGIN_NAMESPACE

class SqliteCipherDriverPlugin : public QSqlDriverPlugin
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID QSqlDriverFactoryInterface_iid FILE "sqlitecipher.json")
public:
    SqliteCipherDriverPlugin();
    virtual ~SqliteCipherDriverPlugin();
    virtual QSqlDriver *create(const QString &) override;
};

QT_END_NAMESPACE

#endif
