//  coverage instrumentation exception handling
//  > works with compilers
//      that support _Pragma(string-literal) directive
//  - documented for:
//    - gcc : https://gcc.gnu.org/onlinedocs/cpp/Pragmas.html
//    - msvc: https://learn.microsoft.com/en-us/cpp/preprocessor/pragma-directives-and-the-pragma-keyword

//  created by Manfred Sorgo
#pragma once
#ifndef COVERAGE_H
#define COVERAGE_H

//  bullseye coverage
#if _BullseyeCoverage
    // pause coverage instrumentation
    #define BULLSEY_PAUSE _Pragma("BullseyeCoverage off")
    // resume coverage instrumentation
    #define BULLSEY_RESUME _Pragma("BullseyeCoverage on")
#else
    #define BULLSEY_PAUSE
    #define BULLSEY_RESUME
#endif

// force coverage of simple boolean expressions
// by converting them to ternary expressions
// TODO: does CTC define something equivalent to _BullseyeCoverage?
#if _BullseyeCoverage or _COVERAGE_ON
    #define B(SIMPLE_EXPR) (SIMPLE_EXPR ? true : false)
#else
    #define B(SIMPLE_EXPR) SIMPLE_EXPR
#endif

#endif // _H
