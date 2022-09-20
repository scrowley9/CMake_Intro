# Set the minimum version of CMake to build project - always needed
cmake_minimum_required(VERSION 3.15.5)

# Name the Project
project(intro)

# Create Variable called SRCs w/ SRC .c files
set(
    SRCs
    ${PROJECT_SOURCE_DIR}/src/main.c
    ${PROJECT_SOURCE_DIR}/src/foo.c
)

# Name the executable Ex: [gcc ... -o out.exe]
# Also, specify src-files to compile into executable
add_executable(
    ${PROJECT_NAME}
    ${SRCs}
    ${PROJECT_SOURCE_DIR}/src/another_src_file.c
)

target_include_directories(
    ${PROJECT_NAME}
    PRIVATE
    ${PROJECT_SOURCE_DIR}/include
    ${PROJECT_SOURCE_DIR}/adder_lib
)

# Setup Subdirectory
add_subdirectory(${PROJECT_SOURCE_DIR}/adder_lib)                                # Include this subdirectory in build process
target_link_directories(${PROJECT_NAME} PRIVATE ${PROJECT_SOURCE_DIR}/adder_lib) # Link Subdirectory to Project

# LINK LIBRARY to Project
target_link_libraries(${PROJECT_NAME} adder)


############################## Add GLFW Submodule ###################################

# Add Subdirectory for GLFW Submodule
add_subdirectory(${PROJECT_SOURCE_DIR}/external/glfw)

# Link GLFW Subdirectory to Project
target_link_directories(${PROJECT_NAME}
    PRIVATE
    ${PROJECT_SOURCE_DIR}/external/glfw/src
)

# Include GLFW headers
target_include_directories(${PROJECT_NAME}
    PUBLIC external/glfw/include
)

# Link Static GLFW3 Library
target_link_libraries(${PROJECT_NAME} glfw)
