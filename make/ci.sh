#!/bin/bash
# build & run for github CI
cd $(dirname $0)
make -j clean
make -j
echo ""

for cpp in $(ls ../tests/); do
    ../build/${cpp%.cpp} X
done
