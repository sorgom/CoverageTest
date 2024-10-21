#pragma once
#ifndef COVERAGE_EX_JUSTIFY_H
#define COVERAGE_EX_JUSTIFY_H

#include <SomeEnum.h>
#include <coverage.h>

int switchCaseJust(const SomeEnum e)
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
        default: // CTC++ Justify | DefensiveDefaults
            break;
BULLSEY_RESUME
    }
    return res;
}

#endif // _H
