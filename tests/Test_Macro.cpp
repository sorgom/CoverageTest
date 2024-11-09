#include <CoverageMacro.h>

#include <use.h>
#include <testlib.h>

TEST(Macro)
{
    const CoverageMacro& cm = CoverageMacro::instance();
    const bool b = cm.getBool1();
    const int i = cm.getInt1();
    use(b, i);
}
