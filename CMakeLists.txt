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
    "include/FpsCounter.hpp"
)

add_library(CoreLib STATIC ${SOURCE} )
target_include_directories(CoreLib PUBLIC include/)
target_link_libraries(CoreLib PUBLIC sfml-graphics sfml-window sfml-system spdlog)

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
target_link_libraries(Game PRIVATE CoreLib sfml-graphics sfml-window sfml-system spdlog)

if(WIN32)
    target_link_libraries(Game PRIVATE sfml-main)
endif()

if (WIN32 AND BUILD_SHARED_LIBS)
    add_custom_command(TARGET Game POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_RUNTIME_DLLS:Game> $<TARGET_FILE_DIR:Game> COMMAND_EXPAND_LISTS)
endif()

set(GAME_SRC_SIMD "src/main_simd.cpp")
add_executable(GameSimd ${GAME_SRC_SIMD})
target_link_libraries(GameSimd PRIVATE CoreLib sfml-graphics sfml-window sfml-system spdlog)

if (WIN32 AND BUILD_SHARED_LIBS)
    add_custom_command(TARGET GameSimd POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_RUNTIME_DLLS:Game> $<TARGET_FILE_DIR:Game> COMMAND_EXPAND_LISTS)
endif()

include(cmake/data.cmake)
add_data_folder(Game)
add_data_folder(GameSimd)

add_subdirectory(tests)
add_subdirectory(benchmarks)
