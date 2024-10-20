#include "test.h"
#include <coding.h>
#include <iostream>
using std::cout;
using std::endl;


class CoTest
{
public:
    INSTANCE_DEC(CoTest)
    void setTest(const char* name, int argc)
    {
        mName = name;
        mCov = argc > 1;
        mNr = 0;
        if ((mName != nullptr) && !mCov)
        {
            cout << "  - " << mName << " no test" << endl;
        }
    }

    void runTest(testfunc func)
    {
        if ((mName != nullptr) && mCov)
        {
            cout << "  - " << mName << " test nr. " << ++mNr << endl;
            func();
        }
    }

private:
    const char* mName = nullptr;
    int mNr = 0;
    bool mCov = false;
};

INSTANCE_DEF(CoTest)

void settest(const char* name, int argc)
{
    CoTest::instance().setTest(name, argc);
}

void test(testfunc func)
{
    CoTest::instance().runTest(func);
}
