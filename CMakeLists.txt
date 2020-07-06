cmake_minimum_required(VERSION 3.10)

#
# Project details
#
project(
    "optimal-ml"
    VERSION 0.1.0
    LANGUAGES C
)

message("\nStarted CMake for ${PROJECT_NAME} v${PROJECT_VERSION}...\n")

#
# Prevent building in the source directory
#
if(PROJECT_SOURCE_DIR STREQUAL PROJECT_BINARY_DIR)
    message(FATAL_ERROR "In-source builds not allowed. Please make a new directory (called a build directory) and run CMake from there.\n")
endif()

#
# Define GSL macros
#
add_compile_definitions(GSL_C99_INLINE)

#
# Disable protections in favor of speed
#
if(${PROJECT_NAME}_ENABLE_OPTIMIZATIONS)
    add_compile_definitions(GSL_RANGE_CHECK_OFF)
endif()

#
# Find all headers and implementation files
#
include(cmake/SourcesAndHeaders.cmake)

#
# This project only builds as a library
#
add_library(
    ${PROJECT_NAME}
    ${headers}
    ${sources}
)

#
# Build tests if configured
#
if(${PROJECT_NAME}_ENABLE_UNIT_TESTING)
    enable_testing()
    message("Building unit tests for the project.\n")
    add_subdirectory(test)
endif()