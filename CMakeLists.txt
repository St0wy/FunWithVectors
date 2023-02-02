cmake_minimum_required(VERSION 3.25)

project("Vectors" VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include(FetchContent)
set(FETCHCONTENT_QUIET FALSE)

set(OpenGL_GL_PREFERENCE GLVND)
set(MSVC_COMPILE_OPTS /nologo /EHsc /GR /W4 /FI iso646.h /WX)
set(GCC_COMPILE_OPTS -Werror -Wpedantic -Wall -Wextra -Wcast-align -Wcast-qual -Wctor-dtor-privacy -Wdisabled-optimization -Wformat=2 -Winit-self -Wlogical-op -Wmissing-declarations -Wmissing-include-dirs -Wold-style-cast -Woverloaded-virtual -Wredundant-decls -Wsign-conversion -Wsign-promo -Wstrict-overflow=5 -Wswitch-default -Wundef -Werror -Wno-unused -Wconversion -Wzero-as-null-pointer-constant )
set(CLANG_COMPILE_OPTS -Werror -Wpedantic -Wall -Wextra -Wcast-align -Wcast-qual -Wctor-dtor-privacy -Wdisabled-optimization -Wformat=2 -Winit-self -Wmissing-declarations -Wmissing-include-dirs -Wold-style-cast -Woverloaded-virtual -Wredundant-decls -Wsign-conversion -Wsign-promo -Wstrict-overflow=5 -Wswitch-default -Wundef -Werror -Wno-unused -Wconversion -Wzero-as-null-pointer-constant -Wno-c++98-compat -Wno-shadow-field-in-constructor -Wno-float-equal )

# Common Lib
set(SOURCE
        "src/math/Vec2.cpp"
        "src/math/Vec3.cpp"
        "src/math/Vec4.cpp"
        "include/math/Vec2.hpp"
        "include/math/Vec3.hpp"
        "include/math/Vec4.hpp"
        "include/Planet.hpp"
        "src/Planet.cpp"
        "include/Consts.hpp"
        "include/math/Utils.hpp" include/PlanetSystem.hpp src/PlanetSystem.cpp)

add_library(CoreLib STATIC ${SOURCE})
target_include_directories(CoreLib PUBLIC include/)
target_link_libraries(CoreLib PUBLIC raylib raylib_cpp spdlog)

if(CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
    target_compile_options(CoreLib PRIVATE ${MSVC_COMPILE_OPTS})
elseif(CMAKE_CXX_COMPILER_ID STREQUAL "GCC")
    target_compile_options(CoreLib PRIVATE ${GCC_COMPILE_OPTS} )
else()
    target_compile_options(CoreLib PRIVATE ${CLANG_COMPILE_OPTS} )
endif()

# CMake other files
include(cmake/libs.cmake)

# Link Game target with main
set(GAME_SRC "src/main.cpp")
add_executable(Game ${GAME_SRC})
target_link_libraries(Game PRIVATE CoreLib raylib raylib_cpp spdlog)

if(CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
    target_compile_options(CoreLib PRIVATE ${MSVC_COMPILE_OPTS})
elseif(CMAKE_CXX_COMPILER_ID STREQUAL "GCC")
    target_compile_options(CoreLib PRIVATE ${GCC_COMPILE_OPTS} )
else()
    target_compile_options(CoreLib PRIVATE ${CLANG_COMPILE_OPTS} )
endif()

add_subdirectory(tests)
