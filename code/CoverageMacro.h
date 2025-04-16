
#ifndef COVERAGE_MACRO_H
#define COVERAGE_MACRO_H

#include <coding.h>

#define MAX(V1, V2) (((V1) > (V2)) ? (V1) : (V2))

//  private members, public getters and setters
#define MEMBER(TYPE, NAME, VAL) \
private: TYPE m ## NAME = VAL; \
public: \
inline TYPE get ## NAME() const { return m ## NAME; } \
inline void set ## NAME(const TYPE val) { m ## NAME = val; }

class CoverageMacro
{
public:
    INSTANCE_DEC(CoverageMacro)

    inline CoverageMacro(int i1=1, int i2=2):
        mInt(MAX(i1, i2))
    {}

    // members and getters
    MEMBER(bool, Bool1, false)
    MEMBER(int, Int1, 11)

    const int mInt;
};

#endif // _H
