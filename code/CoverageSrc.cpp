#include <CoverageSrc.h>
//  full coverage
//  b true / false
CoverageSrc::CoverageSrc(const bool b):
    mBool(b),
    // ternary constructor
    mInt(b ? 1 : 0)
{}

//  full coverage
//  i 0 / 1
CoverageSrc::CoverageSrc(const int i):
    // simple bool constructor
    mBool(i != 0),
    mInt(i)
{}

//  full coverage
//  i 0 / 1
//  b false / true
CoverageSrc::CoverageSrc(const bool b, const int i):
    // constructor or
    mBool(b or i != 0),
    mInt(i),
    // bool and ternary in new array
    mData(new int[b and i > 0? 20 : 10])
{}

//  destructor with if statement
CoverageSrc::~CoverageSrc()
{
    if (mData != nullptr) delete[] mData;
}

//  full coverage
//  b true / false
//  i 0 / 1 / -1
void CoverageSrc::ifElse(const bool b, const int i)
{
    // bool var
    if (b) { pass(); }
    // bool simple
    if (i > 0) { pass(); }
    // bool and
    if (b and i > 0) { pass(); }
    // bool or
    if (b or i > 0) { pass(); }
    else { pass(); }
}

//  return bool simple
bool CoverageSrc::retBoolSimple(const int i1, const int i2)
{
    return i2 > i1;
}

//  return bool and
bool CoverageSrc::retBoolAnd(const int i1, const int i2)
{
    return (i1 > 0) and (i2 > 0);
}
//  return bool or
bool CoverageSrc::retBoolOr(const int i1, const int i2)
{
    return (i1 > 0) or (i2 > 0);
}
//  return ternary
int CoverageSrc::retTernary(const int i1, const int i2)
{
    return i2 > i1 ? i2 : i1;
}

//  call bool simple
void CoverageSrc::callBoolSimple(const int i1, const int i2)
{
    call(i2 > i1);
}
//  call bool and
void CoverageSrc::callBoolAnd(const int i1, const int i2)
{
    call((i1 > 0) and (i2 > 0));
}
//  call bool or
void CoverageSrc::callBoolOr(const int i1, const int i2)
{
    call((i1 > 0) or (i2 > 0));
}
//  call ternary
void CoverageSrc::callTernary(const int i1, const int i2)
{
    call(i2 > i1 ? i2 : i1);
}

//  full coverage
//  i1 0 / 1
//  i2 0 / 1
void CoverageSrc::assignments(const int i1, const int i2)
{
    //  const assignment constructors
    //  simple bool
    const bool cb1 = i1 > 0;
    //  bool and
    const bool cb2 = (i1 > 0) and (i2 > 0);
    //  bool or
    const bool cb3 = (i1 > 0) or (i2 > 0);
    //  ternary
    const int ci1 = (i2 > i1) ? i2 : i1;

    use(ci1, cb1, cb2, cb3);

    //  non const assignment constructors
    //  simple bool
    bool vb1 = i1 > 0;
    //  bool and
    bool vb2 = (i1 > 0) and (i2 > 0);
    //  bool or
    bool vb3 = (i1 > 0) or (i2 > 0);
    //  ternary
    int vi1 = (i2 > i1) ? i2 : i1;

    //  non const assignments
    //  simple bool
    vb1 = i1 == 0;
    //  bool and
    vb2 = (i1 == 0) and (i2 == 0);
    //  bool or
    vb3 = (i1 == 0) or (i2 == 0);
    //  ternary
    vi1 = (i2 == 1) ? i2 : i1;

    use(vb1, vb2, vb3, vi1);

    //  const struct assignment constructors
    //  bool simple
    const SomeStruct cs1 = { i2 > i1, i2 == i1, i2 };
    //  bool and / or
    const SomeStruct cs2 = { vb1 and vb2, vb2 or vb3, i1 };
    //  ternary
    const SomeStruct cs3 = { vb2, vb3, i2 > i1 ? i2 : i1 };

    //  non const struct assignment constructors
    //  bool simple
    SomeStruct vs1 = { i2 > i1, i2 == i1, i2 };
    //  bool and / or
    SomeStruct vs2 = { vb1 and vb2, vb2 or vb3, i1 };
    //  ternary
    SomeStruct vs3 = { vb2, vb3, i2 > i1 ? i2 : i1 };

    use(cs1, cs2, cs3, vs1, vs2, vs3);

    //  new statements
    //  bool simple
    const bool* nbs = new bool(i1 > 0);
    delete nbs;
    //  bool and
    const bool* nba = new bool((i1 > 0) and (i2 > 0));
    delete nba;
    //  bool or
    const bool* nbo = new bool((i1 > 0) or (i2 > 0));
    delete nbo;
    //  ternary array size
    const int* data = new int[i1 > 0 ? 20 : 10];
    delete [] data;
}

//  for loop simple
void CoverageSrc::forLoopSimple(const int i1)
{
    for (int i = 0; i < i1; ++i)
    {
        use(i);
    }
}
//  for loop and
void CoverageSrc::forLoopAnd(const int i1, const int i2)
{
    for (int i = 0; (i < i1) and (i < i2); ++i)
    {
        use(i);
    }
}
//  for loop or
void CoverageSrc::forLoopOr(const int i1, const int i2)
{
    for (int i = 0; (i < i1) or (i < i2); ++i)
    {
        use(i);
    }
}

//  switch case
int CoverageSrc::switchCase(const SomeEnum e)
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
        // not reachable with proper enumeration
        // but testable with cast
        default:
            break;
    }
    return res;
}

void CoverageSrc::tryCatch(const bool b)
{
    try
    {
        if (not b)
        {
            throw false;
        }
    }
    catch(bool e)
    {
        use(e);
    }
}
