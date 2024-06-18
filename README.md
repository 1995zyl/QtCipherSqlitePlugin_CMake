# QtCipherSqlitePlugin_CMake

### QtCipherSqlitePlugin是一种加密SQLite的Qt插件(https://github.com/devbean/QtCipherSqlitePlugin) ，功能强大、使用方便。
### 但由于目前缺少CMake方式构建工程，导致该插件的应用受到了限制，因此提供以cmake的方式构建工程。

编译过程如下：
```
00、git clone --recursive https://github.com/1995zyl/QtCipherSqlitePlugin_CMake
01、进入当前目录，运行python脚本cmake_script.py，将CMakeLists.txt应用到工程中，并打上解决编译错误的patch补丁
02、cd QtCipherSqlitePlugin
1、mkdir build
2、cd build
3、cmake .. -DCMAKE_BUILD_TYPE=Release -DQT_SDK_DIR="D:/Qt/6.5.2/msvc2019_64"。
// CMAKE_BUILD_TYPE指定构建类型，默认为Release；如果没有将Qt内容添加到环境变量中，需要指定DQT_SDK_DIR目录。
4、make sqlitecipher
5、make install    // 执行此命令后，会将sqlitecipher动态库安装到qt目录中
6、make test_plugin
7、make demo
8、../bin/test_plugin
9、../bin/demo
```
