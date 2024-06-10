#ifndef SQLITECHIPHER_GLOBAL_H
#define SQLITECHIPHER_GLOBAL_H

#include <QtGlobal>

#if QT_CONFIG(regularexpression)
#define REGULAR_EXPRESSION_ENABLED
#endif
#if QT_CONFIG(timezone)
#define TIMEZONE_ENABLED
#endif

#endif // SQLITECHIPHER_GLOBAL_H
