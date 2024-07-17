	# Minimum CMake version required, we'll just use the latest version.
    cmake_minimum_required(VERSION 3.30.0)
    # Project name, version and description
    project(schiffe-versenken DESCRIPTION "Schiffe Versenken in C++")

    # Create an executable
    add_executable(${PROJECT_NAME}
        src/main.cpp
    )

    # Set C++ version
    set_target_properties(${PROJECT_NAME} PROPERTIES
        CXX_STANDARD 23
        CXX_STANDARD_REQUIRED ON
    )
