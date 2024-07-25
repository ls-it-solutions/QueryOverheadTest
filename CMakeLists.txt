cmake_minimum_required(VERSION 3.29)
project(OrmTest)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)


find_package(Qt5 COMPONENTS
        Core
        REQUIRED)

add_executable(OrmTest main.cpp
        src/A.cpp
        src/A.h
        src/B.cpp
        src/B.h
        src/Base.cpp
        src/Base.h)
target_link_libraries(OrmTest
        Qt5::Core
)

