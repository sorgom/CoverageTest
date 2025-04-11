#!/bin/bash
# build & run for github CI
cd $(dirname $0)
cd ../make
make -j clean
make -j
echo ""

for cpp in $(ls Test_*.make); do
    ../build/linux/${cpp%.make} X
done
