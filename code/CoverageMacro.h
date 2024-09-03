
#pragma once
#ifndef COVERAGEMACRO_H
#define COVERAGEMACRO_H

#define MEMBER(TYPE, NAME, VAL) \
private: \
    TYPE m ## NAME = VAL; \
public: \
    inline TYPE get ## NAME() const { return m ## NAME; } \
    inline void set ## NAME(const TYPE val) { m ## NAME = val; }

class CoverageMacro
{
public:
    inline CoverageMacro() {}
    MEMBER(bool, Bool, false)
    MEMBER(int, Int, 11)
};

#endif // _H

