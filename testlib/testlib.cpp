#include <testlib.h>
#include <iostream>

Test* TestRunner::pStart = nullptr;
Test* TestRunner::pCurr = nullptr;

Test::Test(const char* const name):
    name(name)
{
    TestRunner::add(this);
}

void Test::run()
{
    std::cout << "TEST(" << name << ')' << '\n';
    body();
}

void TestRunner::add(Test* test)
{
    if (pCurr == nullptr)
    {
        pStart = test;
    }
    else
    {
        pCurr->next = test;
    }
    pCurr = test;
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
