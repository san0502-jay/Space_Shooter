cmake_minimum_required(VERSION 4.2)
project(Space_Shooter)

set(CMAKE_CXX_STANDARD 20)


include(FetchContent)
FetchContent_Declare(
        raylib
        GIT_REPOSITORY https://github.com/raysan5/raylib.git
        GIT_TAG 5.5
)
FetchContent_MakeAvailable(raylib)

add_executable(Space_Shooter src/main.cpp
        src/player.cpp
        src/player.h
        src/Game.h
        src/Game.cpp
        src/Bullet.h
        src/Bullet.cpp
        src/Enemy.h
        src/Enemy.cpp
        src/Constants.h)

target_link_libraries(Space_Shooter PRIVATE raylib)
target_link_options(Space_Shooter PRIVATE -static-libgcc -static-libstdc++ -static)

file(COPY Assets DESTINATION ${CMAKE_BINARY_DIR})
