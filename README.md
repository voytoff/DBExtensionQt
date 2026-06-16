# DBExtensionQt
### Install on Windows
Скачиваем установщик MariaDB Connector/C x64:
https://mariadb.com/docs/connectors/mariadb-connector-c/install-mariadb-connector-c
в c:/MariaDB/Connector без пробелов и ->
```bash
mkdir build-sqldrivers
cd build-sqldrivers
set PATH=C:\Qt\Tools\CMake_64\bin;C:\Qt\Tools\Ninja;C:\Qt\Tools\mingw1310_64\bin;%PATH%
cmake --version
Ninja --version
g++ --version

cmake -G Ninja C:\Qt\6.11.1\Src\qtbase\src\plugins\sqldrivers -DCMAKE_INSTALL_PREFIX=C:\Qt\6.11.1\mingw_64 -DMySQL_INCLUDE_DIR="C:\mariadb-12.3.2-winx64\include\mysql" -DMySQL_LIBRARY="C:\mariadb-12.3.2-winx64\lib\libmariadb.lib"
!!! C:\Qt\6.11.1\mingw_64\bin\qt-cmake.bat -G Ninja C:\Qt\6.11.1\Src\qtbase\src\plugins\sqldrivers -DCMAKE_INSTALL_PREFIX="C:\Qt\6.11.1\mingw_64" -DMySQL_INCLUDE_DIR="C:\MariaDB\Connector\include" -DMySQL_LIBRARY="C:\MariaDB\Connector\lib\libmariadb.lib"
cmake --build .
cmake --install .
```

## Linux
```bash
sudo apt-get install libqt6sql6-mysql  # For Qt6
sudo apt-get install libqt5sql5-mysql  # For Qt5
```


## MariaDB Connector/C
Установите MariaDB Connector/C в зависимости от вашей операционной системы:
Ubuntu / Debian / Linux Mint:
Используйте команду:
sudo apt install libmariadb-dev
Windows:
Скачайте официальный MSI-установщик с MariaDB Connector/C
https://mariadb.com/docs/connectors/mariadb-connector-c/install-mariadb-connector-c
и выполните установку.
macOS:
Выполните в терминале:
brew install mariadb-connector-c
