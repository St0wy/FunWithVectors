include(FetchContent)

# raylib
FetchContent_Declare(
        raylib
        GIT_REPOSITORY https://github.com/raysan5/raylib.git
        GIT_TAG 4.2.0
        GIT_PROGRESS TRUE
        SYSTEM
)
FetchContent_MakeAvailable(raylib)

if(CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
    target_compile_options(raylib PRIVATE "/W0")
else()
    target_compile_options(raylib PRIVATE "-w")
endif()

# raylib-cpp
FetchContent_Declare(
        raylib_cpp
        GIT_REPOSITORY https://github.com/RobLoach/raylib-cpp.git
        GIT_TAG v4.2.8
        GIT_PROGRESS TRUE
        SYSTEM
)
FetchContent_MakeAvailable(raylib_cpp)

FetchContent_Declare(
        spdlog
        GIT_REPOSITORY https://github.com/gabime/spdlog.git
        GIT_TAG v1.11.0
        GIT_PROGRESS TRUE
        SYSTEM
)
FetchContent_MakeAvailable(spdlog)

if(CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
    target_compile_options(raylib PRIVATE "/W0")
else()
    target_compile_options(raylib PRIVATE "-w /EHs")
endif()
