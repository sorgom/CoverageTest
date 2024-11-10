#include <testlib.h>
#include <iostream>
using std::cout;

Test* TestRunner::pStart = nullptr;
Test* TestRunner::pCurr = nullptr;

Test::Test(const char* const name):
    name(name)
{
    TestRunner::add(this);
}

void Test::run()
{
    cout << "TEST(" << name << ')' << '\n';
    body();
}

void TestRunner::add(Test* test)
{
    if (pCurr == nullptr)
    {
        pStart = test;
        pCurr = test;
    }
    else
    {
        pCurr->next = test;
        pCurr = test;
    }
}

void TestRunner::run()
{
    Test* pTest = pStart;
    while (pTest != nullptr)
    {
        pTest->run();
        pTest = pTest->next;
    }
}
