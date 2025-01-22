#include <CoverageMacro.h>

#include <use.h>
#include <testlib.h>

TEST(Macro)
{
    CoverageMacro& cm = CoverageMacro::instance();
    const bool b = cm.getBool1();
    const int i = cm.getInt1();
    cm.setInt1(42);
    cm.setBool1(true);
    use(b, i);
}
