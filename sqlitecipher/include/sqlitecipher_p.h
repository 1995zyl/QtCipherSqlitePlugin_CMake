#ifndef SQLITECIHPERDRIVER_H
#define SQLITECIHPERDRIVER_H

#include <QSqlDriver>

#include "sqlitecipher_global.h"

struct sqlite3;

#ifdef QT_PLUGIN
#define Q_EXPORT_SQLDRIVER_SQLITE
#else
#define Q_EXPORT_SQLDRIVER_SQLITE Q_SQL_EXPORT
#endif

QT_BEGIN_NAMESPACE

class QSqlResult;
class SQLiteCipherDriverPrivate;

class Q_EXPORT_SQLDRIVER_SQLITE SQLiteCipherDriver : public QSqlDriver
{
    Q_DECLARE_PRIVATE(SQLiteCipherDriver)
    Q_OBJECT
    friend class SQLiteResultPrivate;

public:
    explicit SQLiteCipherDriver(QObject *parent = nullptr);
    explicit SQLiteCipherDriver(sqlite3 *connection, QObject *parent = nullptr);
    ~SQLiteCipherDriver();
    bool hasFeature(DriverFeature f) const Q_DECL_OVERRIDE;
    bool open(const QString &db,
              const QString &user = QString(),
              const QString &password = QString(),
              const QString &host = QString(),
              int port = -1,
              const QString &connOpts = QString()) Q_DECL_OVERRIDE;
    void close() Q_DECL_OVERRIDE;
    QSqlResult *createResult() const Q_DECL_OVERRIDE;
    bool beginTransaction() Q_DECL_OVERRIDE;
    bool commitTransaction() Q_DECL_OVERRIDE;
    bool rollbackTransaction() Q_DECL_OVERRIDE;
    QStringList tables(QSql::TableType) const Q_DECL_OVERRIDE;

    QSqlRecord record(const QString &tablename) const Q_DECL_OVERRIDE;
    QSqlIndex primaryIndex(const QString &table) const Q_DECL_OVERRIDE;
    QVariant handle() const Q_DECL_OVERRIDE;
    QString escapeIdentifier(const QString &identifier, IdentifierType) const Q_DECL_OVERRIDE;

    bool subscribeToNotification(const QString &name) Q_DECL_OVERRIDE;
    bool unsubscribeFromNotification(const QString &name) Q_DECL_OVERRIDE;
    QStringList subscribedToNotifications() const Q_DECL_OVERRIDE;
private Q_SLOTS:
    void handleNotification(const QString &tableName, qint64 rowid);
};

QT_END_NAMESPACE

#endif // SQLITECIHPERDRIVER_H
