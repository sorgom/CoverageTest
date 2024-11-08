#include <TestRunner.h>
#include <iostream>
using std::cout;

Test* TestRunner::pStart = nullptr;
Test* TestRunner::pCurr = nullptr;

Test::Test(const char* const name):
    name(name)
{
    TestRunner::add(this);
    if (name != nullptr)
    {
        cout << "Adding test: " << name << '\n';
    }
}

void Test::run()
{
    if (name != nullptr)
    {
        cout << "TEST(" << name << ')' << '\n';
    }
    body();
}

void TestRunner::add(Test* test)
{
    cout << "Adding test\n";
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
