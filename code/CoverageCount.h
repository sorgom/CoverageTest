#ifndef COVERAGE_COUNT_H
#define COVERAGE_COUNT_H

#include <SomeEnum.h>

//  just call and return
inline void oneFunc()
{
}

//  switch case single return
int switchCaseSingle(const SomeEnum e)
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
        default:
            break;
    }
    return res;
}

//  switch case multiple return
int switchCaseMulti(const SomeEnum e)
{
    switch (e)
    {
        case VALUE_A:
            return 0;
        case VALUE_B:
        case VALUE_C:
            return 1;
        default:
            return -1;
    }
}

#endif // _H
