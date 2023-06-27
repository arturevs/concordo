cmake_minimum_required(VERSION 3.12)
project(concordo)

# Add the include directory
include_directories(include)

# Collect all the source files
file(GLOB SOURCES "source/*.cpp")

# Create the executable
add_executable(${PROJECT_NAME} ${SOURCES})
