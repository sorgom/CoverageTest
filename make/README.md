# Make Section
- VS solution
- Makefile
- Premake5 file (requires [premake5](https://premake.github.io/))
- Sample cmd scripts to run CTC++ coverage, require:
  - CTC++
  - [gow (gnu on Windows)](https://github.com/bmatzelle/gow)
  - msbuild / gnumake / nmake
- Sample cmd scripts to run Bullseye coverage, require:
  - Bullseye
  - gow 
  - msbuild / gnumake

All script calls:
```shell
CoverageTest\make> script.cmd [configuration]
```
e.g.
```shell
CoverageTest\make> bullseye_msbuild.cmd 2017
```
To find out configurations call:
```shell
CoverageTest\make> make help
```
