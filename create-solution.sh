name=$1

mkdir $name/
cd $name/

mkdir src/ test/

touch test/example.{in,out}
cp ../Makefile.template ./Makefile
cp ../main.cpp.template ./src/main.cpp

sed -i "s/SOLUTION_NAME/${name,,}/" Makefile