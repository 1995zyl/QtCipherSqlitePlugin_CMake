#ifndef __TEST_SQLITE3MC_h__
#define __TEST_SQLITE3MC_h__

class Sqlite3mcBaseTest
{
public:
    Sqlite3mcBaseTest();
    bool checkOpen();
    bool checkCreateTable();
    bool checkQueryData();
    bool checkInsertData();
};

class Sqlite3mcEncryptionTest
{
public:
    Sqlite3mcEncryptionTest();
    bool checkSetPassword();
    bool checkUpdatePassword();
    bool checkRemovePassword();
};

#endif