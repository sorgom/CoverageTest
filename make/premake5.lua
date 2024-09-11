--  ============================================================
--  premake5 build rules for coverage test
--  ============================================================

buildoptions_vs = '/std:c++17 /MP /W4 /wd4100 /wd4103'
buildoptions_gcc = '-std=c++17 -pedantic-errors -Wall'
buildDir = '../build'


workspace 'CoverageTest'
    -- location '../build'

    configurations { 'ci', 'debug' }
    language 'C++'
    targetdir '../build'
    objdir  '../build/obj/%{cfg.name}'
    
    includedirs { '../test', '../code' }

    filter { 'action:vs*' }
        warnings 'high'
        buildoptions { buildoptions_vs }

    filter { 'action:gmake*' }
        buildoptions { buildoptions_gcc }

    filter { 'configurations:ci' }
        defines { 'NDEBUG' }

    filter { 'configurations:debug' }
        defines { 'DEBUG' }
        symbols 'On'

    project 'CoverageTest'
        kind 'ConsoleApp'
        files { 
            '../code/*.cpp',            
            '../test/*.cpp'
        }
       
