--  ============================================================
--  premake5 build rules for coverage test
--  ============================================================

buildoptions_vs = '/std:c++17 /MP /W4 /wd4100 /wd4103 /wd4068 /D_COVERAGE_ON'
buildoptions_gcc = '-std=c++17 -pedantic-errors -D_COVERAGE_ON'

workspace 'Tests'
    configurations { 'ci' }
    language 'C++'
    targetdir '../build'
    objdir  '../build/%{_TARGET_OS}'
    defines { 'NDEBUG' }
    kind 'ConsoleApp'
    includedirs { '../testlib', '../code' }
    libdirs { '../build/%{_TARGET_OS}/lib' }

    filter { 'action:vs*' }
        warnings 'high'
        buildoptions { buildoptions_vs }

    filter { 'action:gmake*' }
        buildoptions { buildoptions_gcc }

    project 'testlib'
        kind 'StaticLib'
        targetdir '../build/%{_TARGET_OS}/lib'
        files { '../testlib/*.cpp' }

    project 'Test_Standard'
        files { '../tests/Test_Standard.cpp', '../code/CoverageSrc.cpp' }
        links { 'testlib' }

    project 'Test_Standard_Part'
        files { '../tests/Test_Standard_Part.cpp', '../code/CoverageSrc.cpp' }
        links { 'testlib' }

    project 'Test_B_Macro'
        files { '../tests/Test_B_Macro.cpp' }
        links { 'testlib' }

    project 'Test_Count'
        files { '../tests/Test_Count.cpp' }
        links { 'testlib' }

    project 'Test_Exclude'
        files { '../tests/Test_Exclude.cpp' }
        links { 'testlib' }

    project 'Test_FD_SET_Macro'
        files { '../tests/Test_FD_SET_Macro.cpp' }
        links { 'testlib' }

    project 'Test_Macro'
        files { '../tests/Test_Macro.cpp', '../code/CoverageMacro.cpp' }
        links { 'testlib' }

    project 'Test_Mod_Cpp'
        files { '../tests/Test_Mod_Cpp.cpp' }
        links { 'testlib' }
