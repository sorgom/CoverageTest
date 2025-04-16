#   ============================================================
#   CMake for CTC Coverage
#   ============================================================

cmake_minimum_required(VERSION 3.7)


set (projektName CoverageTest)
project(${projektName})

set(REPO_PATH          ${PROJECT_SOURCE_DIR}/..)
set(CODE_PATH          ${REPO_PATH}/code)
set(TESTLIB_PATH       ${REPO_PATH}/testlib)
set(TESTS_PATH         ${REPO_PATH}/tests)
set(LIBRARY_OUTPUT_PATH     ${CMAKE_CURRENT_LIST_DIR})
set(EXECUTABLE_OUTPUT_PATH  ${CMAKE_CURRENT_LIST_DIR})

include_directories (
    ${CODE_PATH}
    ${TESTLIB_PATH}
)

set(CMAKE_CXX_COMPILER_FORCED TRUE)
set(CMAKE_CXX_COMPILER "ctc")

set(CMAKE_CXX_COMPILER_ARG1 "-C \"CONST_INSTR = ON\" -C \"NO_EXCLUDE+*\\code\\*\" -v -i m cl -c")

find_library (
    CtcWin
    NAMES ctcwin32.lib
    HINTS C:/Testwell/CTC/Lib
    NO_DEFAULT_PATH
)
file(GLOB testLibSrcs ${TESTLIB_PATH}/*.cpp)
add_library(_testlib OBJECT ${testLibSrcs})

add_executable(Test_Standard ${TESTS_PATH}/Test_Standard.cpp ${CODE_PATH}/CoverageSrc.cpp)
target_link_libraries(Test_Standard ${CtcWin} _testlib)

add_executable(Test_Standard_Part ${TESTS_PATH}/Test_Standard_Part.cpp ${CODE_PATH}/CoverageSrc.cpp)
target_link_libraries(Test_Standard_Part ${CtcWin} _testlib)

add_executable(Test_B_Macro ${TESTS_PATH}/Test_B_Macro.cpp)
target_link_libraries(Test_B_Macro ${CtcWin} _testlib)

add_executable(Test_Count ${TESTS_PATH}/Test_Count.cpp)
target_link_libraries(Test_Count ${CtcWin} _testlib)

add_executable(Test_Exclude ${TESTS_PATH}/Test_Exclude.cpp)
target_link_libraries(Test_Exclude ${CtcWin} _testlib)

add_executable(Test_FD_SET_Macro ${TESTS_PATH}/Test_FD_SET_Macro.cpp)
target_link_libraries(Test_FD_SET_Macro ${CtcWin} _testlib)

add_executable(Test_Macro ${TESTS_PATH}/Test_Macro.cpp ${CODE_PATH}/CoverageMacro.cpp)
target_link_libraries(Test_Macro ${CtcWin} _testlib)

add_executable(Test_Mod_Cpp ${TESTS_PATH}/Test_Mod_Cpp.cpp)
target_link_libraries(Test_Mod_Cpp ${CtcWin} _testlib)
