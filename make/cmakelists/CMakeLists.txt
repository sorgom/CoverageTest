#   CMake File for CTC Coverage

cmake_minimum_required(VERSION 3.7)

set (projektName CoverageTest)
project(${projektName})

set(REPO_PATH               ${PROJECT_SOURCE_DIR}/..)
set(CODE_PATH               ${REPO_PATH}/code)
set(TEST_PATH               ${REPO_PATH}/tests)
set(TLIB_PATH               ${REPO_PATH}/testlib)
set(EXECUTABLE_OUTPUT_PATH  ${CMAKE_CURRENT_LIST_DIR})

include_directories (
    ${CODE_PATH}
    ${TLIB_PATH}
)

file(GLOB allSrcs 
    ${CODE_PATH}/*.cpp
    ${TEST_PATH}/Tests_1998.cpp
    ${TLIB_PATH}/*.cpp
)

set(CMAKE_CXX_COMPILER "ctc")

set(CMAKE_CXX_COMPILER_ARG1 "-C \"NO_EXCLUDE+*\\code\\*\" -C \"CONST_INSTR = ON\" -i m cl -c")

find_library (
    CtcWin
    NAMES ctcwin32.lib
    HINTS C:/Testwell/CTC/Lib
    NO_DEFAULT_PATH
)

add_executable(${projektName} ${allSrcs})
target_link_libraries(${projektName} ${CtcWin})
