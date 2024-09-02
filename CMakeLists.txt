# Minimum CMake version required
cmake_minimum_required(VERSION 3.10)

# Project name, version, and description
project(battleship VERSION 1.0 DESCRIPTION "Battleship game in C++")

# Create an executable
add_executable(${PROJECT_NAME}
    src/main.cpp
    src/multiplayer.hpp
    src/game.hpp
    src/input.hpp
    src/output.hpp
    src/reset.hpp
    src/setup.hpp
    src/termcolor.hpp
)

# Set C++ version
set_target_properties(${PROJECT_NAME} PROPERTIES
    CXX_STANDARD 23
    CXX_STANDARD_REQUIRED ON
)
