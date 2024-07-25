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
        src/domain/A.cpp
        src/domain/A.h
        src/domain/B.cpp
        src/domain/B.h
        src/domain/Base.cpp
        src/domain/Base.h
        src/database/Mapper.cpp
        src/database/Mapper.h)
target_link_libraries(OrmTest
        Qt5::Core
)

