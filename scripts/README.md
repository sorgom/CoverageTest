# make and run section
## Windows / msbuild
### required tools on Windows
- msbuild / Developer Command Prompt
- [premake5](https://premake.github.io/)
- python 3 (associated with *.py)
### prebuild
- call premake5 with your VS version to generate solution
- call premake5 --help to find out how
### build and run scripts
#### coverage_Bullseye.py
- requires Bullseye coverage for Windows
- generates reports_Bullseye folder
  - coverage summary (covsrc)
  - coverage (.cov) files for coverage browser
#### coverage_CTC.py
- requires CTC++ for Windows
- generates reports_CTC folder
  - simple html reports with simple template
  - html folders with CTC html template
#### common usage
##### VS code
- setup Developer Command Prompt terminal see [howto](https://github.com/sorgom/howto/blob/dev/vscode/developer_command_prompt.md)
- start Developer Command Prompt terminal
- drag script into it
##### list of tests
- call scripts with **-l** for available tests
## linux / make Bullseye
### required tools on linux
- make, gcc
- python 3
### build and run scripts
#### coverage_Bullseye.py
- requires Bullseye coverage for linux
- generates reports_Bullseye folder
  - coverage summary (covsrc)
  - coverage (.cov) files for coverage browser
#### usage
- build and run all tests
```shell
dev@linux:scripts$ python3 coverage_Bullseye.py
```
- call script with **-l** for available tests
```shell
dev@linux:scripts$ python3 coverage_Bullseye.py -l
```
- build and run some tests
```shell
dev@linux:scripts$ python3 coverage_Bullseye.py Test1 Test2 ...
```
