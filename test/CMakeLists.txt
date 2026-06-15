cmake_minimum_required(VERSION 3.16)

project(case1 LANGUAGES CXX)

enable_testing()

find_package(QT NAMES Qt6 REQUIRED COMPONENTS
    Gui
    Test
)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS
    Gui
    Test
)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(case1 tst_case1.cpp)
add_test(NAME case1 COMMAND case1)

target_link_libraries(case1 PRIVATE
    Qt${QT_VERSION_MAJOR}::Gui
    Qt${QT_VERSION_MAJOR}::Test
)

