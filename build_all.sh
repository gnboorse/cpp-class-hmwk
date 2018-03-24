#!/bin/bash
dirs="CPA WA_1 WA_2 WA_3 WA_4 WA_5 FinalProject/Part1 FinalProject/Part2 FinalProject/Part3 FinalProject/Part4 FinalProject/Part5"
home=$PWD
for d in $dirs; do
    cd $d/
    echo "Building $d..."
    ./build.sh
    echo "Done"
    cd $home
done