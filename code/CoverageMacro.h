
#pragma once
#ifndef COVERAGEMACRO_H
#define COVERAGEMACRO_H

#include <coding.h>
#include <coverage.h>

#define MODULE_TEST

//  private members and public getters
#define MEMBER(TYPE, NAME, VAL) \
private: TYPE m ## NAME = VAL; \
public: inline TYPE get ## NAME() const { return m ## NAME; } 

//  in module test also public setters
#ifdef MODULE_TEST
#define SETTER(TYPE, NAME) \
public: inline void set ## NAME(const TYPE val) { m ## NAME = val; }
#else
#define SETTER(TYPE, NAME)
#endif

class CoverageMacro
{
public:
    INSTANCE_DEC(CoverageMacro)

    // members and getters
    MEMBER(bool, Bool1, false)
    MEMBER(int, Int1, 11)

    // test code setters: no coverage
    BULLSEY_PAUSE
    #pragma CTC SKIP

    SETTER(bool, Bool1)
    SETTER(int, Int1)
    
    #pragma CTC ENDSKIP
    BULLSEY_RESUME
};

#endif // _H

