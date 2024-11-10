#!/bin/bash

cd $(dirname $0)
make clean
make -j
echo ""

for cpp in $(ls ../tests/); do
    ../build/${cpp%.cpp} X
done
