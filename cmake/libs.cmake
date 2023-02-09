include(FetchContent)

# spdlog
FetchContent_Declare(
        spdlog
        GIT_REPOSITORY https://github.com/gabime/spdlog.git
        GIT_TAG v1.11.0
        GIT_PROGRESS TRUE
        SYSTEM
)
FetchContent_MakeAvailable(spdlog)

if(CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
    target_compile_options(spdlog PRIVATE "/W0")
else()
    target_compile_options(spdlog PRIVATE "-w /EHs")
endif()

# SFML 
FetchContent_Declare(
    sfml
    GIT_REPOSITORY "https://github.com/SFML/SFML.git"
    GIT_TAG        "2.6.x"
    GIT_PROGRESS TRUE
    SYSTEM
)
set(SFML_BUILD_EXAMPLES OFF)
set(SFML_BUILD_DOC OFF)
option(SFML_BUILD_AUDIO "Build audio" OFF)
option(SFML_BUILD_NETWORK "Build network" OFF)
FetchContent_MakeAvailable(sfml)
