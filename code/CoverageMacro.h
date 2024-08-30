#pragma once
#ifndef COVERAGEMACRO_H
#define COVERAGEMACRO_H

#include <Use.h>

#define MEMB(TYPE, NAME, VAL) \
private: \
    TYPE m ## NAME = VAL; \
public: \
    inline TYPE get ## NAME() const { return m ## NAME; } \
    inline void set ## NAME(const TYPE val) { m ## NAME = val; }

class CoverageMacro
{
public:
    inline CoverageMacro() {}
    MEMB(bool, Bool, false)
    MEMB(int, Int1, 11)
    MEMB(int, Int2, 22)
};

class CoverageMacroMcp
{
public:
    inline CoverageMacroMcp() = default;
    MEMB(bool, Bool, false)
    MEMB(int, Int1, 11)
    MEMB(int, Int2, 22)
};

#endif // _H