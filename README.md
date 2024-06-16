# QtCipherSqlitePlugin_CMake

### QtCipherSqlitePlugin是一种加密SQLite的Qt插件(https://github.com/devbean/QtCipherSqlitePlugin) ，功能强大、使用方便。
### 但由于目前缺少CMake方式构建工程，导致该插件的应用受到了限制，因此提供以cmake的方式构建工程。

以MacOS为例，编译过程如下：
```
1、mkdir build
2、cd build
3、cmake .. -DCMAKE_BUILD_TYPE=Debug -DQT_SDK_DIR=xxx!!!todo。CMAKE_BUILD_TYPE指定构建类型，默认为Release；如果没有将Qt内容添加到环境变量中，需要指定DQT_SDK_DIR目录。
4、make sqlitecipher
5、make install
6、make test_plugin
7、make demo
8、../bin/test_plugin
8、../bin/demo
```
