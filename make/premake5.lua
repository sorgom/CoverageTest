--  ============================================================
--  premake5 build rules for coverage test
--  ============================================================

buildoptions_vs = '/std:c++17 /MP /W4 /wd4100 /wd4103'
-- buildoptions_gcc = '-std=c++17 -pedantic-errors -Werror -Wall'
buildoptions_gcc = '-std=c++17 -pedantic-errors -Wall'

workspace 'CoverageTest'
    configurations { 'ci', 'debug' }
    language 'C++'
    
    includedirs { '../test', '../code' }

    filter { 'action:vs*' }
        objdir  '../build/obj/vs/%{prj.name}/%{cfg.name}'
        targetdir '../build/exe'
        warnings 'high'
        buildoptions { buildoptions_vs }

    filter { 'action:gmake*' }
        objdir '../build/obj/gcc/%{prj.name}/%{cfg.name}'
        targetdir '../build/bin'
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
        
