cmake_minimum_required(VERSION 3.17)
project(tst_DBExtension VERSION 0.1 LANGUAGES CXX)
enable_testing()
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 REQUIRED COMPONENTS
    Core
    Gui
    Widgets
    Sql
    Test
)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS
    Core
    Gui
    Widgets
    Sql
    Test
)

include_directories(../lib)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(tst_DBExtension tst_case1.cpp)
add_test(NAME tst_DBExtension COMMAND case1)

target_link_libraries(tst_DBExtension PRIVATE
    Qt${QT_VERSION_MAJOR}::Core
    Qt${QT_VERSION_MAJOR}::Gui
    Qt${QT_VERSION_MAJOR}::Widgets
    Qt${QT_VERSION_MAJOR}::Sql
    Qt${QT_VERSION_MAJOR}::Test
    DBExtension
)

