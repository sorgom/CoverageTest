#pragma once
#ifndef COVERAGE_EX_JUSTIFY_H
#define COVERAGE_EX_JUSTIFY_H

#include <SomeEnum.h>
#include <coverage.h>

namespace justify
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
BULLSEY_PAUSE
            // not reachable with proper enumeration
            // but testable with cast
            default: // CTC++ Justify | DefensiveDefaults: only performed with proper enumeration
                break;
BULLSEY_RESUME
        }
        return res;
    }
} // namespace
#endif // _H
