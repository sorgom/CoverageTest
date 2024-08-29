
#include <CoverageSrc.h>

CoverageSrc::CoverageSrc(bool b):
    mBool(b),
    // ternary constructor
    mInt(b ? 1 : 0)
{}

CoverageSrc::CoverageSrc(int i):
    // simple boolean constructor
    mBool(i != 0),
    mInt(i)
{}

CoverageSrc::CoverageSrc(int i, bool b):
    // constructor and
    mBool(b && i != 0),
    mInt(i)
{}

//  return and
bool CoverageSrc::operator==(const CoverageSrc& other) const
{
    return mBool == other.mBool && mInt == other.mInt;
}

//  return or
bool CoverageSrc::operator!=(const CoverageSrc& other) const
{
    return mBool != other.mBool || mInt != other.mInt;
}

//  return simple bool
bool CoverageSrc::operator<(const CoverageSrc& other) const
{
    return mInt < other.mInt;
}

//  return ternary
int CoverageSrc::realVal() const
{
    return mBool ? mInt + 1 : mInt;
}

//  boolean parameter
bool CoverageSrc::isTrue(bool b)
{
    return b;
}

//  simple boolean call
bool CoverageSrc::hasVal1() const
{
    return isTrue(mInt > 0);
}

//  ternary call
bool CoverageSrc::hasVal2() const
{
    return isTrue(mBool ? mInt > 0 : mInt < 0);
}

//  boolean call and
bool CoverageSrc::hasVal3() const
{
    return isTrue(mBool && mInt > 0);
}

//  boolean call or
bool CoverageSrc::noVal() const
{
    return isTrue((!mBool) || mInt == 0);
}

//  for loop
int CoverageSrc::sum(int lim) const
{
    int sum = 0;
    for (int i = 0; (i < mInt) && (i < lim); ++i)
    {
	    sum += i;
    }
    return sum;
}

//  switch case single return
int CoverageSrc::switchCaseSingle(const int val) const
{
    int res = -1;
    switch (val)
    {
	case 0:
	    res = 0;
	    break;
	case 1:
	case 2:
	    res = 1;
	    break;
	default:
	    break;
    }
    return res;
}

//  switch case multiple return (not allowed with SIL4)
int CoverageSrc::switchCaseMulti(const int val) const
{
    switch (val)
    {
	case 0:
	    return 0;
	case 1:
	case 2:
	    return 1;
	default:
	    return -1;
    }
    // unreachable
    #pragma BullseyeCoverage off
    #pragma CTC SKIP
    return 42;
    #pragma CTC ENDSKIP
    #pragma BullseyeCoverage on
}

void CoverageSrc::assignments(int a, int b) const
{
    //  const assignment constructors
    //  ternary
    const int c1 = a > b ? a : b;
    //  simple boolean
    const bool c2 = a > 0;
    //  boolean and
    const bool c3 = c2 && b > 0;
    //  boolean or
    const bool c4 = c2 || b > 0;

    //  non const assignment constructors
    //  ternary
    int v1 = a > b ? a : b;
    //  simple boolean
    bool v2 = a > 0;
    //  boolean and
    bool v3 = v2 && b > 0;
    //  boolean or
    bool v4 = v2 || b > 0;

    //  non const assignments
    //  ternary
    v1 = a < b ? a : b;
    //  simple boolean
    v2 = a < 0;
    //  boolean and
    v3 = v2 && b < 0;
    //  boolean or
    v4 = v2 || b < 0;
}

int CoverageSrc::ifelse(int val) const
{
    int ret = -1;
    // simple bool
    if (val == 0)
    {
	    ret = 0;
    }
    // bool and
    else if (mBool && val == 1)
    {
	    ret = 1;
    }
    // bool or
    else if ((!mBool) || val < 0)
    {
	    ret = 2;
    }
    else
    {
	    ret = 3;
    }
    return ret;
}
