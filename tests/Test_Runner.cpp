#include <TestRunner.h>
#include <iostream>

struct Runner_01 : Test
{
    Runner_01():
        Test("Runner_01")
    {}
    void body() override;
};


void Runner_01::body()
{
    std::cout << "running ..." << '\n';
}

Runner_01 __Runner_01();
