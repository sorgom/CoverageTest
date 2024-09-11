--  ============================================================
--  premake5 build rules for coverage test
--  ============================================================

buildoptions_vs = '/std:c++17 /MP /W4 /wd4100 /wd4103'
buildoptions_gcc = '-std=c++17 -pedantic-errors -Wall'

workspace 'CoverageTest'

    configurations { '1998', '2017', 'macro' }
    language 'C++'
    targetdir '../build'
    objdir  '../build/obj/%{cfg.name}'
    
    includedirs { '../test', '../code' }

    filter { 'action:vs*' }
        warnings 'high'
        buildoptions { buildoptions_vs }

    filter { 'action:gmake*' }
        buildoptions { buildoptions_gcc }

    filter { 'configurations:1998' }
        files { '../test/Tests_1998.cpp', '../code/*.cpp' }

    filter { 'configurations:2017' }
        files { '../test/Tests_2017.cpp' }

    filter { 'configurations:macro' }
        files { '../test/Tests_Macro.cpp' }

        project 'CoverageTest'
        kind 'ConsoleApp'
        defines { 'DEBUG' }
        symbols 'On'
       
