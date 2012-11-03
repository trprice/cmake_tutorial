cmake_minimum_required (VERSION 2.6)

project (Tutorial)

# Setup the version number
set (Tutorial_VERSION_MAJOR 1)
set (Tutorial_VERSION_MINOR 0)


# Setup the project directories.
set (PROJECT_SOURCE_DIR src)
set (PROJECT_INCLUDE_DIR include)
set (PROJECT_BUILD_INCLUDE_DIR build/include)
set (PROJECT_BIN_DIR bin)
set (PROJECT_LIB_DIR lib)


# Setup output directories
set (CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_LIB_DIR})
set (CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_LIB_DIR})
set (CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BIN_DIR})


# Setup option to use out own math functions
option (USE_MYMATH "Use tutorial provided math functions" ON)


# Check if this system provides the log and exp functions.
include (CheckFunctionExists)
check_function_exists (log HAVE_LOG)
check_function_exists (exp HAVE_EXP)


# Setup a header file to contain global settings
configure_file (
    "${PROJECT_SOURCE_DIR}/TutorialConfig.h.in"
    "${PROJECT_INCLUDE_DIR}/TutorialConfig.h"
    )


# Add the binary directory to the search path.
include_directories("${PROJECT_INCLUDE_DIR}")
include_directories("${PROJECT_BUILD_INCLUDE_DIR}")


if (USE_MYMATH)
    include_directories("${PROJECT_SOURCE_DIR}/MathFunctions/include")
    add_subdirectory (${PROJECT_SOURCE_DIR}/MathFunctions)
    set (EXTRA_LIBS ${EXTRA_LIBS} MathFunctions)
endif (USE_MYMATH)


# Add the executable
add_executable (Tutorial ${PROJECT_SOURCE_DIR}/tutorial.cpp)


# Set compiler flags.
set_target_properties(Tutorial
  PROPERTIES
  COMPILE_FLAGS "-g3")


# Add libraries to be linked
target_link_libraries (Tutorial ${EXTRA_LIBS})


# Add the install targets.
#       These are relative to CMAKE_INSTALL_PREFIX
set (CMAKE_INSTALL_PREFIX /Users/trprice)

install (TARGETS Tutorial DESTINATION bin)
install (FILES ${PROJECT_BUILD_INCLUDE_DIR}/TutorialConfig.h DESTINATION include)
