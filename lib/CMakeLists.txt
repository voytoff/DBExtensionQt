cmake_minimum_required(VERSION 3.20)
project(DBExtension LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 REQUIRED COMPONENTS
  Core
  Sql
)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS
  Core
  Sql
)

add_library(DBExtension SHARED
  DBExtension_global.h
  dbextension.h dbextension.cpp
  db.h db.cpp
)

target_link_libraries(DBExtension PRIVATE
  Qt${QT_VERSION_MAJOR}::Core
  Qt${QT_VERSION_MAJOR}::Sql
)

target_compile_definitions(DBExtension PRIVATE DBEXTENSION_LIBRARY)
