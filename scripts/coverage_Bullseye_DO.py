#   ms build run all available tests with Bullseye coverage
#   using sompy docopts module for options and help
if __name__ == '__main__':
    from coverage_Bullseye import run, __doc__ as bdoc, reportsDir
    from coverage_common import testList, vsBuild
    import sompy
    from docopts import docopts

    help = bdoc + """
usage: this script [options] [tests]
options:
-c  clean build and reports folder
-l  list available tests
-h  this help
"""
    opts, args = docopts(help)
    if opts.get('l'):
        print('available tests:', *testList(), sep='\n')
        exit(0)
    if opts.get('c'):
        from shutil import rmtree
        rmtree(reportsDir, ignore_errors=True)
        vsBuild('Clean')

    run(args or testList())
