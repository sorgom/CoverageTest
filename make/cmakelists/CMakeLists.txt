#   ============================================================
#   CMake File fuerCTC Coverage

cmake_minimum_required(VERSION 3.7)

# BEGIN DOCKER WORKAROUND (see https://stackoverflow.com/questions/56877220/how-do-i-set-compile-options-for-cmake-msvc-build-in-docker)
set(CMAKE_C_COMPILER_FORCED TRUE)
set(CMAKE_CXX_COMPILER_FORCED TRUE)
# END DOCKER WORKAROUND

set (projektName CoverageTest)
project(${projektName})

#  Standard Linker Flags
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} /FORCE:MULTIPLE /DEBUG /IGNORE:4006" )
#  Sichere Compiler Optionen
set(SAVE_COMPILE_OPTONS "/Zc:threadSafeInit-")

set(REPO_PATH               ${PROJECT_SOURCE_DIR}/..)
set(CODE_PATH               ${REPO_PATH}/code)
set(TEST_PATH               ${REPO_PATH}/test)
set(LIBRARY_OUTPUT_PATH     ${CMAKE_CURRENT_LIST_DIR})
set(EXECUTABLE_OUTPUT_PATH  ${CMAKE_CURRENT_LIST_DIR})

include_directories (
    ${CODE_PATH}
    ${TEST_PATH}
)

file(GLOB allSrcs 
    ${CODE_PATH}/*.cpp
    ${TEST_PATH}/*.cpp
)

set(CMAKE_CXX_COMPILER "ctc")

# Instrumentierung
# -i f: function coverage
# -i d: decition coverage
# -i m: multicondition coverage
#
# Damit auch die Header Dateien mit einbezogen werden, muss in der ctc.ini
# EXCLUDE = 
# also leer stehen 
set(CMAKE_CXX_COMPILER_ARG1 "-C \"NO_EXCLUDE+*\\modules\\*\" -v -i m cl -c")

# add_definitions(-Dfar= " " -Dnear= " " -DCPM32_USE_CLIB -DSW_RELEASE=0 -DSW_UPDATE=0 -DSW_REPAIR=0 -DSW_BUILD=0)

find_library (
    CtcWin
    NAMES ctcwin32.lib
    HINTS C:/Testwell/CTC/Lib
    NO_DEFAULT_PATH
)

add_executable(${projektName} ${allSrcs})
target_compile_options(${projektName} PRIVATE ${SAVE_COMPILE_OPTONS})
target_link_libraries(${projektName} ${CppUTest} ${CtcWin})
