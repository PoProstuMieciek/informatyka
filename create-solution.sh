#!/bin/bash

root=$(pwd)/
path=$1
[ "${path: -1}" == "/" ] && path=${path%/}
solution_name=$(echo $path | tac -s / | head -1)

mkdir -p $path/
cd $path/

mkdir src/ test/
touch test/example.{in,out}
cp $root/.templates/src.main.cpp.template ./src/main.cpp
cp $root/.templates/test.main.cpp.template ./test/main.cpp
cp $root/.templates/test.test.sh.template ./test/test.sh

cp $root/.templates/Makefile.template ./Makefile
sed -i "s/SOLUTION_NAME/${solution_name,,}/" ./Makefile
sed -i "s/SOLUTION_NAME/${solution_name,,}/" ./test/test.sh

code ./src/main.cpp
pwd