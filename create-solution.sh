name=$1

mkdir $name/
cd $name/

mkdir src/
touch src/main.cpp

cp ../Makefile ./
sed -i "s/SOLUTION_NAME/${name,,}/" Makefile