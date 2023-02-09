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

add_executable(VectorBenchmarks "Vec2Bench.cpp")
target_link_libraries(VectorBenchmarks PRIVATE CoreLib benchmark::benchmark)

add_executable(PlanetsBenchmarks "PlanetsBench.cpp")
target_link_libraries(PlanetsBenchmarks PRIVATE CoreLib benchmark::benchmark)

if (WIN32 AND BUILD_SHARED_LIBS)
    add_custom_command(TARGET VectorBenchmarks POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_RUNTIME_DLLS:VectorBenchmarks> $<TARGET_FILE_DIR:VectorBenchmarks> COMMAND_EXPAND_LISTS)
    add_custom_command(TARGET PlanetsBenchmarks POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_RUNTIME_DLLS:PlanetsBenchmarks> $<TARGET_FILE_DIR:PlanetsBenchmarks> COMMAND_EXPAND_LISTS)
endif()

if(MSVC)
    target_compile_options(VectorBenchmarks PUBLIC /arch:AVX2 /Oi /GR- /EHs-c- /FA /Oy- /GL)
    target_link_options(VectorBenchmarks PUBLIC /LTCG)
else()
    target_compile_options(VectorBenchmarks PUBLIC "-march=haswell" "-masm=intel" -fno-rtti -fno-exceptions -save-temps -fno-omit-frame-pointer -flto -ffast-math)
    target_link_options(VectorBenchmarks PUBLIC -flto)
endif()
