--  ============================================================
--  premake5 build rules for coverage test
--  ============================================================

buildoptions_vs = '/std:c++17 /MP /W4 /wd4100 /wd4103 /D_COVERAGE_ON'
buildoptions_gcc = '-std=c++17 -pedantic-errors -D_COVERAGE_ON'

workspace 'CoverageTest'

    configurations { 
        'standard', 'mod_cpp', 'macro', 'b_macro', 'fd_set', 'exclude', 'count' 
    }
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

    filter { 'configurations:standard' }
        files { '../tests/Tests_standard.cpp', '../code/CoverageSrc.cpp' }
        
    filter { 'configurations:mod_cpp' }
        files { '../tests/Tests_Mod_Cpp.cpp' }

    filter { 'configurations:macro' }
        files { '../tests/Tests_Macro.cpp', '../code/CoverageMacro.cpp' }

    filter { 'configurations:b_macro' }
        files { '../tests/Tests_B_Macro.cpp' }

    filter { 'configurations:exclude' }
        files { '../tests/Tests_Exclude.cpp' }

    filter { 'configurations:fd_set' }
        files { '../tests/Tests_FD_SET.cpp' }

    filter { 'configurations:count' }
        files { '../tests/Tests_Count.cpp' }

    project 'CoverageTest'
        kind 'ConsoleApp'
        defines { 'NDEBUG' }
       
