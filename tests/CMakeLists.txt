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
    target_compile_options(gtest PRIVATE "-w")
endif()

enable_testing()
include(GoogleTest)

set(TEST_SOURCE
        "Vec2Tests.cpp"
        "Vec3Tests.cpp"
        "Vec4Tests.cpp"
        "Vec2xNTests.cpp"
        )
add_executable(VectorTests ${TEST_SOURCE})
target_link_libraries(VectorTests PRIVATE CoreLib GTest::gtest GTest::gtest_main)

gtest_discover_tests(VectorTests)
