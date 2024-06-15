import shutil
import os

def copy_cmakefiles():
    if os.path.exists('main_cmake.txt'):
        shutil.move('main_cmake.txt', 'QtCipherSqlitePlugin/CMakeLists.txt') 
    if os.path.exists('sqlitecipher_cmake.txt'):
        shutil.move('sqlitecipher_cmake.txt', 'QtCipherSqlitePlugin/sqlitecipher/CMakeLists.txt') 
    if os.path.exists('test_plugin_cmake.txt'):
        shutil.move('test_plugin_cmake.txt', 'QtCipherSqlitePlugin/test_plugin/CMakeLists.txt') 

def copy_cmakeDir():
    if os.path.exists('cmake'):
        shutil.move('cmake', 'QtCipherSqlitePlugin/cmake') 

def apply_patch():
    gitCommand = "git -C ./QtCipherSqlitePlugin" + " apply " + os.getcwd() + "/QtCipherSqlitePlugin.patch"
    gitCommand=gitCommand.replace('\\','/')
    result = os.popen(gitCommand) # 执行输入的命令
    print(result.read())

if __name__ == "__main__":
    copy_cmakefiles()
    copy_cmakeDir()
    apply_patch()