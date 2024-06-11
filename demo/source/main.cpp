#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "doctest/doctest.h"
#include "test_sqlite3mc.h"

TEST_SUITE("test sqlite3mc suite")
{
    TEST_CASE("test sqlite3mc no encryption")
    {
        Sqlite3mcBaseTest baseTest;
    }

    TEST_CASE("test sqlite3mc encryption")
    {
        Sqlite3mcEncryptionTest encryptionTest;
    }
}