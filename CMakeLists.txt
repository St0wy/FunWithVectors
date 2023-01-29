cmake_minimum_required(VERSION 3.24)

include(FetchContent)

project("Vectors" VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED True)

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
find_package(raylib QUIET)
if (NOT raylib_FOUND)
    include(FetchContent)
    FetchContent_Declare(
            raylib
            GIT_REPOSITORY https://github.com/raysan5/raylib.git
            GIT_TAG 4.2.0
    )
    FetchContent_MakeAvailable(raylib)
endif()

# raylib-cpp
find_package(raylib_cpp QUIET)
if (NOT raylib_cpp_FOUND)
    include(FetchContent)
    FetchContent_Declare(
            raylib_cpp
            GIT_REPOSITORY https://github.com/RobLoach/raylib-cpp.git
            GIT_TAG v4.2.8
    )
    FetchContent_MakeAvailable(raylib_cpp)
endif()

include(cmake/data.cmake)

set(MAIN "src/main.cpp")
add_executable(Game ${MAIN})
target_link_libraries(Game PRIVATE CoreLib raylib raylib_cpp)

add_data_folder(Game)
#set_target_properties (Game_Copy_Data PROPERTIES FOLDER Game/Main)

# TESTS

include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

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




