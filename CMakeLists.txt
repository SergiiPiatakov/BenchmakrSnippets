cmake_minimum_required (VERSION 3.5)

include (ExternalProject)

set (CMAKE_CXX_STANDARD 11)
set (CMAKE_CXX_STANDARD_REQUIRED ON)
set (CMAKE_CXX_EXTENSIONS OFF)



# Benchmark based on the Google benchmark Framework.
ExternalProject_Add (
    benchmark
    GIT_REPOSITORY "https://github.com/google/benchmark.git"
    GIT_TAG "v1.5.0"
    CMAKE_ARGS "-DBENCHMARK_ENABLE_TESTING=OFF;-DCMAKE_BUILD_TYPE=Release"
    SOURCE_DIR "${PROJECT_BINARY_DIR}/benchmark"
    BINARY_DIR "${PROJECT_BINARY_DIR}/benchmark"
    INSTALL_COMMAND ""
    TEST_COMMAND ""
)
set_target_properties (benchmark PROPERTIES EXCLUDE_FROM_ALL TRUE)
set (GBENCHMARK_FOUND true)
set (GBENCHMARK_INCLUDE_DIR "${PROJECT_BINARY_DIR}/benchmark/include")
set (GBENCHMARK_LIBRARY "${PROJECT_BINARY_DIR}/benchmark/src/libbenchmark.a")

set (BenchmarkGoogle_SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/main_google.cpp)
add_executable (benchmark_google ${BenchmarkGoogle_SOURCES})
include_directories (${GBENCHMARK_INCLUDE_DIR})
target_link_libraries (benchmark_google ${GBENCHMARK_LIBRARY} pthread)
add_dependencies (benchmark_google benchmark)



# Benchmark based on the hayai Framework.
ExternalProject_Add (
    hayai
    GIT_REPOSITORY "https://github.com/nickbruun/hayai.git"
    SOURCE_DIR "${PROJECT_BINARY_DIR}/hayai"
    BUILD_COMMAND ""
    INSTALL_COMMAND ""
    TEST_COMMAND ""
)
set_target_properties (hayai PROPERTIES EXCLUDE_FROM_ALL TRUE)
set (HAYAI_FOUND true)
set (HAYAI_INCLUDE_DIR "${PROJECT_BINARY_DIR}/hayai/src")

set (BenchmarkHayai_SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/main_hayai.cpp)
add_executable (benchmark_hayai ${BenchmarkHayai_SOURCES})
include_directories (${HAYAI_INCLUDE_DIR})
target_link_libraries (benchmark_hayai)
add_dependencies (benchmark_hayai hayai)



# Benchmark based on the Celero Framework.
ExternalProject_Add (
    Celero
    GIT_REPOSITORY "https://github.com/DigitalInBlue/Celero.git"
    GIT_TAG "v2.6.0"
    PATCH_COMMAND eval "sed 's/CACHE.*FORCE//g' CMakeLists.txt > CMakeLists.mod && mv CMakeLists.mod CMakeLists.txt"
    CMAKE_ARGS "-DCELERO_ENABLE_EXPERIMENTS=OFF;-DCMAKE_BUILD_TYPE=Release"
    SOURCE_DIR "${PROJECT_BINARY_DIR}/Celero"
    BINARY_DIR "${PROJECT_BINARY_DIR}/CeleroBuild"
    INSTALL_COMMAND ""
    TEST_COMMAND ""
)
set_target_properties (Celero PROPERTIES EXCLUDE_FROM_ALL TRUE)
set (CELERO_FOUND true)
set (CELERO_INCLUDE_DIR "${PROJECT_BINARY_DIR}/Celero/include")
set (CELERO_LIBRARY "${PROJECT_BINARY_DIR}/CeleroBuild/libcelero.so")

set (BenchmarkCelero_SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/main_celero.cpp)
add_executable (benchmark_celero ${BenchmarkCelero_SOURCES})
include_directories (${CELERO_INCLUDE_DIR})
target_link_libraries (benchmark_celero ${CELERO_LIBRARY})
add_dependencies (benchmark_celero Celero)
