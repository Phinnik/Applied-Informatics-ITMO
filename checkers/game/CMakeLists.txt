project(game)

set(SOURCES
        Game.cpp
        Graphics.cpp
        Logic.cpp)
set(HEADERS
        Game.h
        Graphics.h
        Logic.h)

include_directories(../)

add_library(game ${SOURCES} ${HEADERS})