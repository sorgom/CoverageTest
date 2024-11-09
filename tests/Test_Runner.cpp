#include <Test.h>
#include <iostream>

struct Runner_01 : Test
{
    Runner_01():
        Test("Runner_01")
    {}
    void body() override;
};

Runner_01 __Runner_01;

void Runner_01::body()
{
    std::cout << "running ..." << '\n';
}

TEST(Runner_02)
{
    std::cout << "running ..." << '\n';
}
