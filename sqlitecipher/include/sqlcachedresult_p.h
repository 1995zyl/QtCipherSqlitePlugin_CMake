#ifndef SQLCACHEDRESULT_H
#define SQLCACHEDRESULT_H

#include <QSqlResult>

#include "sqlitecipher_global.h"

QT_BEGIN_NAMESPACE

class SqlCachedResultPrivate;

class SqlCachedResult : public QSqlResult
{
public:
    virtual ~SqlCachedResult();

    typedef QVector<QVariant> ValueCache;

protected:
    SqlCachedResult(const QSqlDriver *db);

    void init(int colCount);
    void cleanup();
    void clearValues();

    virtual bool gotoNext(ValueCache &values, int index) = 0;

    QVariant data(int i) Q_DECL_OVERRIDE;
    bool isNull(int i) Q_DECL_OVERRIDE;
    bool fetch(int i) Q_DECL_OVERRIDE;
    bool fetchNext() Q_DECL_OVERRIDE;
    bool fetchPrevious() Q_DECL_OVERRIDE;
    bool fetchFirst() Q_DECL_OVERRIDE;
    bool fetchLast() Q_DECL_OVERRIDE;

    int colCount() const;
    ValueCache &cache();

    void virtual_hook(int id, void *data) Q_DECL_OVERRIDE;
    void detachFromResultSet() Q_DECL_OVERRIDE;
    void setNumericalPrecisionPolicy(QSql::NumericalPrecisionPolicy policy) Q_DECL_OVERRIDE;

private:
    bool cacheNext();
    SqlCachedResultPrivate *d;
};

QT_END_NAMESPACE

#endif // SQLCACHEDRESULT_H