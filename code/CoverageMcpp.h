#pragma once
#ifndef COVERAGEMCPP_H
#define COVERAGEMCPP_H

#include <SomeStruct.h>
#include <use.h>

class CoverageMcpp
{
public:
    inline CoverageMcpp(const int i = 0):
        // mod cpp member struct constructor bool simple
        mStruct{i < 0, i > 0, i}
    {}

    inline CoverageMcpp(const int i, const bool b):
        // mod cpp member struct constructor bool and / or, ternary
        mStruct{b and i < 0, b or i > 0, b ? 1 : 0}
    {}

    void assignments(const int i1, const int i2) const
    {
        //  const mod cpp constructors
        //  simple bool
        const bool cb1 { i1 > 0 };
        //  bool and
        const bool cb2 {cb1 and i2 > 0};
        //  bool or
        const bool cb3 {cb2 or i2 > 0};
        //  ternary
        const int ci1 { cb3 ? i1 : i2 };
        
        use(ci1, cb1, cb2, cb3);

        //  mod cpp non const constructors
        //  simple bool
        bool vb1 { i1 > 0 };
        //  bool and
        bool vb2 { vb1 and i2 > 0 };
        //  bool or
        bool vb3 { vb2 or i2 > 0 };
        //  ternary
        int vi1 { vb3 ? i1 : i2 };

        use(vi1, vb1, vb2, vb3);

        //  mod cpp const struct constructors
        //  bool simple 
        const SomeStruct cs1 { ci1 < vi1, ci1 > vi1, vi1 };
        //  bool and / or
        const SomeStruct cs2 { vb2 and ci1 > vi1, vb3 or ci1 < vi1, ci1 };
        //  ternary
        const SomeStruct cs3 { vb2, vb3, vb1 ? vi1 : ci1 };

        //  mod cpp const struct constructors
        //  bool simple 
        SomeStruct vs1 { ci1 < vi1, ci1 > vi1, vi1 };
        //  bool and / or
        SomeStruct vs2 { vb2 and ci1 > vi1, vb3 or ci1 < vi1, ci1 };
        //  ternary
        SomeStruct vs3 { vb2, vb3, vb1 ? vi1 : ci1 };

        use(cs1, cs2, cs3, vs1, vs2, vs3);
        
    }

    const SomeStruct mStruct;
};

#endif // _H
