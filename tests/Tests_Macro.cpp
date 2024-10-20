#include <CoverageMacro.h>

#include <use.h>
#include <test.h>

void Test01()
{
    const CoverageMacro& cm = CoverageMacro::instance();
    const bool b = cm.getBool1();
    const int i = cm.getInt1();
    use(b, i);
} 

int main(const int argc, const char**)
{
    setTest("macros", argc);
    runTest(Test01);
    return 0;
}