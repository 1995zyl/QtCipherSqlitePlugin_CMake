# sqlitecipher

1、SQLite3MultipleCiphers编译，编译为静态库。用VS 2022打开\build\sqlite3mc_vc17.sln编译生成sqlite3mc_x64.lib。
    msbuild sqlite3mc_vc17.sln /p:Configuration=Debug
    msbuild sqlite3mc_vc17.sln /p:Configuration=Release