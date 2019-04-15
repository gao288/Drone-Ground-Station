#! /bin/bash
if [[ "$OSTYPE" == "linux-gnu" ]]; then Qt_PATH=$HOME/Qt/5.13.0/gcc_64
        # ...
elif [[ "$OSTYPE" == "darwin"* ]]; then Qt_PATH=$HOME/Qt/5.12.2/clang_64
        # Mac OSX
fi

rm -r build
mkdir -p build && cd build

cmake -DCMAKE_PREFIX_PATH=$Qt_PATH ..
make -j8

cd camera
./camera
