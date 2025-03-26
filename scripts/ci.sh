#!/bin/bash
# build & run for github CI
cd $(dirname $0)
cd ../make
make -j clean
make -j
echo ""

for cpp in $(ls ../tests/); do
    ../build/linux/${cpp%.cpp} X
done
