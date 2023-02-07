set(BENCHMARK_VERSION "v1.7.1")

FetchContent_Declare(
    benchmark
    GIT_REPOSITORY "https://github.com/google/benchmark.git"
    GIT_TAG        "${BENCHMARK_VERSION}"
    GIT_PROGRESS TRUE
    SYSTEM
)

set(BENCHMARK_DOWNLOAD_DEPENDENCIES ON)
FetchContent_MakeAvailable(benchmark)

set(BENCH_SOURCE "Vec2Bench.cpp")
add_executable(VectorBenchmarks ${BENCH_SOURCE})
target_link_libraries(VectorBenchmarks PRIVATE CoreLib benchmark::benchmark)

if(MSVC)
    target_compile_options(VectorBenchmarks PUBLIC /arch:AVX2 /Oi /GR- /EHs-c- /FA /Oy- /GL)
    target_link_options(VectorBenchmarks PUBLIC /LTCG)
else()
    target_compile_options(VectorBenchmarks PUBLIC "-march=haswell" "-masm=intel" -fno-rtti -fno-exceptions -save-temps -fno-omit-frame-pointer -flto -ffast-math)
    target_link_options(VectorBenchmarks PUBLIC -flto)
endif()
