cmake_minimum_required(VERSION 2.8)
cmake_policy(SET CMP0015 NEW)

project(htui_webassembly)

set(CMAKE_VERBOSE_MAKEFILE on)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/web)

file(GLOB_RECURSE CORE_HDR src/*.h)
file(GLOB_RECURSE CORE_SRC src/*.cpp)

add_executable(function ${CORE_SRC} ${CORE_HDR})

# specify flags to when linking the target
target_link_libraries(function "-s WASM=1")
target_link_libraries(function "-s ASSERTIONS=1")
target_link_libraries(function "-g4 --source-map-base http://localhost:8080/")
target_link_libraries(function "-lm -O2 -Wc++11-extensions")
target_link_libraries(function "-s \"EXTRA_EXPORTED_RUNTIME_METHODS=['ccall', 'cwrap']\"")
target_link_libraries(function "-s EXPORTED_FUNCTIONS=\"['_int_sqrt', '_addNums', '_sortNums', '_fib', '_fibNext', '_next_val', '_new_fib']\"")

set_target_properties(function PROPERTIES LINK_FLAGS "--preload-file ${CMAKE_SOURCE_DIR}")
