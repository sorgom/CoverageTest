#include <TestRunner.h>

Test* TestRunner::pStart = nullptr;
Test* TestRunner::pCurr = nullptr;

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
