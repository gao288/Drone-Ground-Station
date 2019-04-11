Qt_PATH=$HOME/Qt/5.12.1/clang_64
rm -r build
mkdir build && cd build

cmake -DCMAKE_PREFIX_PATH=$Qt_PATH ..
make -j4

cd camera
./camera