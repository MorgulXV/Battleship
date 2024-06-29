	# Minimum CMake version required, we'll just use the latest version.
    cmake_minimum_required(VERSION 3.22.9)
    # Project name, version and description
    project(schiffe-versenken DESCRIPTION "Schiffe Versenken in C++")

    # Create an executable
    add_executable(${PROJECT_NAME}
        src/main.cpp
    )

    # Set C++ version
    set_target_properties(${PROJECT_NAME} PROPERTIES
        CXX_STANDARD 17
        CXX_STANDARD_REQUIRED ON
    )

    find_path(DPP_INCLUDE_DIR NAMES dpp/dpp.h HINTS ${DPP_ROOT_DIR})

    find_library(DPP_LIBRARIES NAMES dpp "libdpp.a" HINTS ${DPP_ROOT_DIR})
    
    include(FindPackageHandleStandardArgs)
    
    find_package_handle_standard_args(DPP DEFAULT_MSG DPP_LIBRARIES DPP_INCLUDE_DIR)
    