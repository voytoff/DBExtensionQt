# DBExtensionQt
### Install on Windows
```bash
mkdir build-sqldrivers
cd build-sqldrivers
set PATH=C:\Qt\Tools\CMake_64\bin;C:\Qt\Tools\Ninja;C:\Qt\Tools\mingw1310_64\bin;%PATH%
cmake --version
Ninja --version
g++ --version

cmake -G Ninja C:\Qt\6.11.1\Src\qtbase\src\plugins\sqldrivers -DCMAKE_INSTALL_PREFIX=C:\Qt\6.11.1\mingw_64 -DMySQL_INCLUDE_DIR="C:\mariadb-12.3.2-winx64\include\mysql" -DMySQL_LIBRARY="C:\mariadb-12.3.2-winx64\lib\libmariadb.lib"

cmake -G Ninja C:\Qt\6.11.1\Src\qtbase\src\plugins\sqldrivers -DCMAKE_INSTALL_PREFIX=C:\Qt\6.11.1\mingw_64 -DMySQL_INCLUDE_DIR="C:\mariadb-12.3.2-winx64\include\mysql" -DMySQL_LIBRARY="C:\mariadb-12.3.2-winx64\lib\libmariadb.lib"

cmake --build .
cmake --install .
```

## Linux
```bash
sudo apt-get install libqt6sql6-mysql  # For Qt6
sudo apt-get install libqt5sql5-mysql  # For Qt5
```