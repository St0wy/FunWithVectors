cmake_minimum_required (VERSION 3.24)

include(FetchContent)

project("Vectors" VERSION 0.1.0)

set (CMAKE_CXX_STANDARD 20)
set (CMAKE_CXX_STANDARD_REQUIRED True)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

include_directories(include/)

set(SOURCE
	#"src/main.cpp"
    "src/Vec2.cpp"
	"src/Vec2Tests.cpp"
#	"src/Vec3.cpp"
#	"src/Vec4.cpp"
	"include/Vec2.hpp"
#	"include/Vec3.hpp"
#	"include/Vec4.hpp"
)

add_executable(${PROJECT_NAME} ${SOURCE})


target_link_libraries(${PROJECT_NAME} GTest::gtest_main)

include(GoogleTest)
gtest_discover_tests(${PROJECT_NAME})