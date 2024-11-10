#pragma once
#ifndef COVERAGE_EX_SKIP_H
#define COVERAGE_EX_SKIP_H

#include <SomeEnum.h>
#include <coverage.h>

int switchCaseSkip(const SomeEnum e)
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
//  DefensiveDefaults
BULLSEY_PAUSE
#pragma CTC SKIP
        default:
            break;
#pragma CTC ENDSKIP
BULLSEY_RESUME
    }
    return res;
}

#endif // _H
