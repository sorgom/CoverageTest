# Make Section
## windows msbuild
### required tools for all scripts
- msbuild
- [premake5](https://premake.github.io/)
### prebuild
- call premake5 with your VS version to generate solution
- call premake5 --help to find out how
### build and run scripts
- Bullseye_msbuild.cmd
  - requires Bullseye coverage
  - generates reports_bullseye folder
- CTC_msbuild.cmd
  - requires CTC++
  - generates reports_ctc folder
## linux
currently only build and run script for github CI
- no tools required
