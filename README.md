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

Далее закидываем файл библиотеки libmariadb.dll из **C:\Program Files\MariaDB XX.X\lib** в **C:\Qt\Tools\mingwXXXX_64\bin**, если выбран MinGW.
Возможно эту библиотеку придется кинуть в каталог с программой...

## Linux
```bash
sudo apt update
sudo apt install mariadb-server
sudo mysql_secure_installation # ???

sudo systemctl status mariadb
```

- Для того чтобы подключиться к самой консоли управления базами данных, используйте:
```bash
sudo mariadb
```

# Настроить удаленный доступ к MariaDB
### Измените адрес прослушивания (Bind-Address)
По умолчанию MariaDB принимает соединения только с локального компьютера (127.0.0.1).
```bash
sudo nano /etc/mysql/mariadb.conf.d/50-server.cnf
```
заменить:
bind-address = **127.0.0.1** -> bind-address = **0.0.0.0**
чтобы сервер принимал подключения со всех IP-адресов

- Перезапустите службу MariaDB, чтобы применить настройки:
```bash
sudo systemctl restart mariadb
```

- Откройте порт в брандмауэре (UFW):
```bash
sudo ufw allow from 192.168.1.50 to any port 3306
или
sudo ufw allow 3306/tcp
```

- Создайте удаленного пользователя
- Предоставьте пользователю права на нужную базу данных
- Обновите привилегии и выйдите
```bash
sudo mariadb
CREATE USER 'mmp'@'%' IDENTIFIED BY '2026';
или CREATE USER 'mmp'@'192.168.1.50' IDENTIFIED BY '2026';
GRANT ALL PRIVILEGES ON 106org.* TO 'mmp'@'%';
FLUSH PRIVILEGES;
EXIT;
```

### Проверить подключение
```bash
mysql -u remote_user -h SERVER_IP -p
```

# QT+MariaDB
- Установите зависимости и библиотеки MariaDB:
```bash
sudo apt update
sudo apt install libmariadb-dev build-essential libgl1-mesa-dev

sudo apt-get install libqt6sql6-mysql  # For Qt6
sudo apt-get install libqt5sql5-mysql  # For Qt5
```
(Пакет libmariadb-dev предоставит нужные файлы библиотек вроде libmariadb.so).

* Подготовьте исходный код драйверов Qt:
Убедитесь, что при установке Qt 6.11.1 через Qt Online Installer вы отметили галочкой компонент Sources.
Внутри вашей папки установки Qt должен присутствовать путь к исходникам плагина:
~/Qt/6.11.1/Src/qtbase/src/plugins/sqldrivers/

## Скомпилируйте драйвер с помощью qt-cmake
В Qt 6 сборка осуществляется через CMake. Создайте отдельную директорию для сборки вне дерева исходников, чтобы не засорять код
```bash
# Перейдите в домашнюю директорию или каталог сборки
cd ~
mkdir build_qt_mysql && cd build_qt_mysql

# Запустите конфигурацию cmake, указав пути к вашей версии Qt
~/Qt/6.11.1/gcc_64/bin/qt-cmake ~/Qt/6.11.1/Src/qtbase/src/plugins/sqldrivers/

# Соберите только плагин поиска MySQL/MariaDB
cmake --build . --target qsqlmysql
```
Примечание: qt-cmake автоматически найдет установленный в системе libmariadb-dev в стандартных путях /usr/include/mariadb

- Установите готовый драйвер в структуру Qt
```bash
cmake --install .
```
Она автоматически скопирует скомпилированный файл **libqsqlmysql.so** в директорию плагинов вашей рабочей среды:
~/Qt/6.11.1/gcc_64/plugins/sqldrivers/

## Установка нативной версии HeidiSQL
Перейдите на официальный сайт загрузки HeidiSQL и в разделе Linux скачайте актуальный пакет (например, Linux 64 bit Debian package with QT6 build).
https://www.heidisql.com/download.php

Установите скачанный .deb пакет через терминал (замените путь на ваш файл):
```bash
sudo apt install ~/Downloads/heidisql_*.deb
или
curl -L -o /tmp/libqt6pas6_6.2.10-1_amd64.deb https://github.com/davidbannon/libqt6pas/releases/download/v6.2.10/libqt6pas6_6.2.10-1_amd64.deb
sudo apt install /tmp/libqt6pas6_6.2.10-1_amd64.deb
```

Есть альтернативы, DBeaver, Antares SQL, 

# Способ 2. Установка Windows-версии через Wine / Snap
```bash
sudo snap install heidisql-wine --beta
```

# ...

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

## Изменить порт
### Linux
- Откройте конфигурационный файл:
```bash
sudo nano /etc/mysql/mariadb.conf.d/50-server.cnf  # Для Ubuntu/Debian
# или
sudo nano /etc/my.cnf.d/server.cnf
```
- Измените порт
```
[mysqld]
port = 3307
```
- Перезапустите службу базы данных
```bash
sudo systemctl restart mariadb
# или
sudo systemctl restart mysql
```
- Проверьте результат:
```bash
sudo ss -tulpn | grep mysqld
```

## Windows
Тоже самое в файле C:\Program Files\MariaDB XX.X\data\my.ini