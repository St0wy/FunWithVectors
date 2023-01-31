cmake_minimum_required(VERSION 3.25)

include(FetchContent)
set(FETCHCONTENT_QUIET FALSE)

project("Vectors" VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(OpenGL_GL_PREFERENCE GLVND)

# COMMON LIB

set(SOURCE
        "src/Vec2.cpp"
        "src/Vec3.cpp"
        "src/Vec4.cpp"
        "include/Vec2.hpp"
        "include/Vec3.hpp"
        "include/Vec4.hpp"
        )

add_library(CoreLib ${SOURCE})
target_include_directories(CoreLib PUBLIC include/)

# MAIN GAME

# raylib
FetchContent_Declare(
        raylib
        GIT_REPOSITORY https://github.com/raysan5/raylib.git
        GIT_TAG 4.2.0
        SYSTEM
)
FetchContent_MakeAvailable(raylib)

if(CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
    target_compile_options(raylib PRIVATE "/W0")
else()
    target_compile_options(raylib PRIVATE "-w") # works even if -fno-rtti is set to CXX_FLAGS
endif()

# raylib-cpp
FetchContent_Declare(
        raylib_cpp
        GIT_REPOSITORY https://github.com/RobLoach/raylib-cpp.git
        GIT_TAG v4.2.8
        SYSTEM
)
FetchContent_MakeAvailable(raylib_cpp)

include(cmake/data.cmake)

set(MAIN "src/main.cpp")
add_executable(Game ${MAIN})
target_link_libraries(Game PRIVATE CoreLib raylib raylib_cpp)

add_data_folder(Game)

# TESTS

include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
        SYSTEM
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

if(CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
    target_compile_options(gtest PRIVATE "/W0")
else()
    target_compile_options(gtest PRIVATE "-w") # works even if -fno-rtti is set to CXX_FLAGS
endif()

enable_testing()

set(TEST_SOURCE
        "tests/Vec2Tests.cpp"
        "tests/Vec3Tests.cpp"
        "tests/Vec4Tests.cpp"
        )
add_executable(VectorTests ${TEST_SOURCE})
target_link_libraries(VectorTests PRIVATE GTest::gtest GTest::gtest_main CoreLib)

include(GoogleTest)
gtest_discover_tests(VectorTests)




