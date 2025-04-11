# make and run section
## windows msbuild scripts
### required tools for all scripts
- msbuild / Developer Command Prompt
- [premake5](https://premake.github.io/)
- python 3
### prebuild
- call premake5 with your VS version to generate solution
- call premake5 --help to find out how
### build and run scripts
#### coverage_Bullseye.py
- requires Bullseye coverage
- generates reports_Bullseye folder
  - coverage summary (covsrc)
  - coverage (.cov) files for coverage browser
#### coverage_CTC.py
- requires CTC++
- generates reports_CTC folder
  - simple html reports with simple template
  - html folders with CTC html template
#### common usage
call scripts with **-l** for available tests
## linux
currently only build and run script for github CI
- no tools required
