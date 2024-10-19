--  ============================================================
--  premake5 build rules for coverage test
--  ============================================================

buildoptions_vs = '/std:c++17 /MP /W4 /wd4100 /wd4103 /D_COVERAGE_ON'
buildoptions_gcc = '-std=c++17 -pedantic-errors -Wall -D_COVERAGE_ON'

workspace 'CoverageTest'

    configurations { '1998', '2017', 'macro', 'b_macro' }
    language 'C++'
    targetdir '../build'
    objdir  '../build/obj/%{cfg.name}'
    
    includedirs { '../testlib', '../code' }
    files { '../testlib/*.cpp' }

    filter { 'action:vs*' }
        warnings 'high'
        buildoptions { buildoptions_vs }

    filter { 'action:gmake*' }
        buildoptions { buildoptions_gcc }

    filter { 'configurations:1998' }
        files { '../tests/Tests_1998.cpp', '../code/*.cpp' }

    filter { 'configurations:2017' }
        files { '../tests/Tests_2017.cpp' }

    filter { 'configurations:macro' }
        files { '../tests/Tests_Macro.cpp' }

    filter { 'configurations:b_macro' }
        files { '../tests/Tests_B.cpp' }

        project 'CoverageTest'
        kind 'ConsoleApp'
        defines { 'DEBUG' }
        symbols 'On'
       
