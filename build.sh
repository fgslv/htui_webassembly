rm -rf build
mkdir build
cd build
emcc -o function.js ../cpp/function.cpp ../cpp/fib.cpp -s ASSERTIONS=1 -g4 --source-map-base http://localhost:8080/index.html -lm -O2 -Wc++11-extensions -s WASM=1 -s EXPORTED_FUNCTIONS="['_int_sqrt', '_addNums', '_sortNums', '_fib', '_fibNext', '_next_val', '_new_fib']" -s "EXTRA_EXPORTED_RUNTIME_METHODS=['ccall', 'cwrap']"
mv function.js ../web/gen/
mv function.wasm ../web/gen/
mv function.wasm.map ../web/gen/
cd .. && rm -rf build
