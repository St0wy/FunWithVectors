cmake_minimum_required(VERSION 3.25)

project("Vectors" VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include(FetchContent)
set(FETCHCONTENT_QUIET FALSE)

set(OpenGL_GL_PREFERENCE GLVND)

# Common Lib
set(SOURCE
    "src/math/Vec2.cpp"
    "src/math/Vec3.cpp"
    "src/math/Vec4.cpp"
    "include/math/Vec2.hpp"
    "include/math/Vec3.hpp"
    "include/math/Vec4.hpp"
    "include/math/Vec2xN.hpp"
    "include/Planet.hpp"
    "src/Planet.cpp"
    "include/Consts.hpp"
    "include/math/Utils.hpp" 
    "include/PlanetSystem.hpp" 
    "src/PlanetSystem.cpp"
    "include/intrinsics.hpp"
    "include/SimdPlanetSystem.hpp"
)

add_library(CoreLib STATIC ${SOURCE} )
target_include_directories(CoreLib PUBLIC include/)
target_link_libraries(CoreLib PUBLIC raylib raylib_cpp spdlog)

if(MSVC)
    target_compile_options(CoreLib PUBLIC /arch:AVX2 /Oi /GR- /EHs-c- /FA /Oy- /GL)
    target_link_options(CoreLib PUBLIC /LTCG)
else()
    target_compile_options(CoreLib PUBLIC "-march=haswell" "-masm=intel" -fno-rtti -fno-exceptions -save-temps -fno-omit-frame-pointer -flto -ffast-math)
    target_link_options(CoreLib PUBLIC -flto)
endif()

# CMake other files
include(cmake/libs.cmake)

# Link Game target with main
set(GAME_SRC "src/main.cpp")
add_executable(Game ${GAME_SRC})
target_link_libraries(Game PRIVATE CoreLib raylib raylib_cpp spdlog)

set(GAME_SRC_SIMD "src/main_simd.cpp")
add_executable(GameSimd ${GAME_SRC_SIMD})
target_link_libraries(GameSimd PRIVATE CoreLib raylib raylib_cpp spdlog)

add_subdirectory(tests)
add_subdirectory(benchmarks)
