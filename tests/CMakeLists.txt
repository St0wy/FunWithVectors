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
        )
add_executable(VectorTests ${TEST_SOURCE})
target_link_libraries(VectorTests PRIVATE CoreLib GTest::gtest GTest::gtest_main)

if(CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
    target_compile_options(VectorTests PRIVATE "/Wall" "/WX")
else()
    target_compile_options(VectorTests PRIVATE -Werror -Wpedantic -Wall -Wextra -Wcast-align -Wcast-qual -Wctor-dtor-privacy -Wdisabled-optimization -Wformat=2 -Winit-self -Wlogical-op -Wmissing-declarations -Wmissing-include-dirs -Wnoexcept -Wold-style-cast -Woverloaded-virtual -Wredundant-decls -Wsign-conversion -Wsign-promo -Wstrict-null-sentinel -Wstrict-overflow=5 -Wswitch-default -Wundef -Werror -Wno-unused -Wconversion -Wzero-as-null-pointer-constant -Wuseless-cast )
endif()

gtest_discover_tests(VectorTests)
