--  ============================================================
--  premake5 build rules for coverage test
--  ============================================================

buildoptions_vs = '/std:c++17 /MP /W4 /wd4100 /wd4103 /wd4068'
buildoptions_gcc = '-std=c++17 -pedantic-errors -Werror -Wall -Wno-unknown-pragmas'

workspace 'Tests'
    configurations { 'ci' }
    language 'C++'
    targetdir '../build'
    objdir  '../build/%{_TARGET_OS}'
    defines { 'NDEBUG' }
    kind 'ConsoleApp'
    includedirs { '../testlib', '../code' }
    defines { '_COVERAGE_ON' }

    filter { 'action:vs*' }
        warnings 'high'
        buildoptions { buildoptions_vs }

    filter { 'action:gmake*' }
        buildoptions { buildoptions_gcc }

    filter { 'kind:ConsoleApp' }
        libdirs { '../build/%{_TARGET_OS}/lib' }
        links { 'testlib' }

    project 'Test_Standard'
        files { '../tests/Test_Standard.cpp', '../code/CoverageSrc.cpp' }

    project 'Test_Standard_Part'
        files { '../tests/Test_Standard_Part.cpp', '../code/CoverageSrc.cpp' }

    project 'Test_B_Macro'
        files { '../tests/Test_B_Macro.cpp' }

    project 'Test_Count'
        files { '../tests/Test_Count.cpp' }

    project 'Test_Exclude'
        files { '../tests/Test_Exclude.cpp' }

    project 'Test_FD_SET_Macro'
        files { '../tests/Test_FD_SET_Macro.cpp' }

    project 'Test_Macro'
        files { '../tests/Test_Macro.cpp', '../code/CoverageMacro.cpp' }

    project 'Test_Mod_Cpp'
        files { '../tests/Test_Mod_Cpp.cpp' }

    project 'testlib'
        kind 'StaticLib'
        targetdir '../build/%{_TARGET_OS}/lib'
        files { '../testlib/*.cpp' }
