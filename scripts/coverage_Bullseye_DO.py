"""
ms build and run tests with Bullseye coverage

usage: this script [options] [tests]
options:
-c  clean build and reports folder
-l  list available tests
-h  this help
"""
if __name__ == '__main__':
    from coverage_Bullseye import run, reportsDir
    from coverage_common import testList, vsBuild, showTests
    import sompy
    from docopts import docopts

    opts, args = docopts(__doc__)
    if opts.get('l'):
        showTests()
    if opts.get('c'):
        from shutil import rmtree
        rmtree(reportsDir, ignore_errors=True)
        vsBuild('clean')

    run(args or testList())
