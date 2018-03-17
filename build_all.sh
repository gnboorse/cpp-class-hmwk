#!/bin/bash

for d in */; do
    cd $d
    echo "Building $d..."
    ./build.sh
    echo "Done"
    cd ..
done