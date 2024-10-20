#pragma once
#ifndef COVERAGE_EX_SKIP_H
#define COVERAGE_EX_SKIP_H

#include <SomeEnum.h>
#include <coverage.h>

namespace skip
{
    //  switch case single return
    static int switchCaseSingle(const SomeEnum e)
    {
        int res = -1;
        switch (e)
        {
            case VALUE_A:
                res = 0;
                break;
            case VALUE_B:
            case VALUE_C:
                res = 1;
                break;
//  DefensiveDefaults: only performed with proper enumeration
BULLSEY_PAUSE
#pragma CTC SKIP
            // not reachable with proper enumeration
            // but testable with cast
            default:
                break;
#pragma CTC ENDSKIP
BULLSEY_RESUME
        }
        return res;
    }
} // namespace
#endif // _H
