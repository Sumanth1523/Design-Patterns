# Example CMake file for compiling & linking a project with the the SQLiteCpp wrapper
#
# Copyright (c) 2012-2020 Sebastien Rombauts (sebastien.rombauts@gmail.com)
#
# Distributed under the MIT License (MIT) (See accompanying file LICENSE.txt
# or copy at http://opensource.org/licenses/MIT)
cmake_minimum_required(VERSION 3.1) # for "CMAKE_CXX_STANDARD" version
project(SQLiteCpp_Example VERSION 2.0)

# SQLiteC++ 3.x now requires C++11 compiler
cmake_minimum_required(VERSION 3.16)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")
# First, find sdbus-c++
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(inc)

set(SOURCES
    main.cpp 
    src/READY.cpp
    src/SOLD_OUT.cpp
    src/TICKET_SOLD.cpp
    src/VALIDATING.cpp
    src/TicketMachine.cpp
)

set(HEADERS
    inc/Enums.h
    inc/State.h
    inc/StatesBlock.h
    inc/TicketMachine.h
)

# Add main.cpp example source code to the executable
add_executable(StateTicketMachine ${SOURCES} ${HEADERS})
