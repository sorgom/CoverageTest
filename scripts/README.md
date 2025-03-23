# make and run section
## windows msbuild
### required tools for all scripts
- msbuild
- [premake5](https://premake.github.io/)
### prebuild
- call premake5 with your VS version to generate solution
- call premake5 --help to find out how
### build and run scripts
#### Bullseye_msbuild.cmd
- requires Bullseye coverage
- generates reports_bullseye folder
  - coverage summary (covsrc)
  - .cov files for coverage browser
  - todo html files (covbr / covbr2html**)
  - optional html folders
#### CTC_msbuild.cmd
- requires CTC++
- generates reports_ctc folder
  - simple html reports
  - optional html folders
#### usage
call scripts with **-h**
## linux
currently only build and run script for github CI
- no tools required

## covbr2html
** for information about covbr2html see [covbr2html repo](https://github.com/sorgom/covbr2html)
