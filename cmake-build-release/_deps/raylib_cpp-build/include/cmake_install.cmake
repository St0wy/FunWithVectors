# Install script for directory: /home/stowy/dev/FunWithVectors/cmake-build-release/_deps/raylib_cpp-src/include

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/usr/local")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Release")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "0")
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

# Set default install directory permissions.
if(NOT DEFINED CMAKE_OBJDUMP)
  set(CMAKE_OBJDUMP "/usr/bin/objdump")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include" TYPE FILE FILES
    "/home/stowy/dev/FunWithVectors/cmake-build-release/_deps/raylib_cpp-src/include/AudioDevice.hpp"
    "/home/stowy/dev/FunWithVectors/cmake-build-release/_deps/raylib_cpp-src/include/AudioStream.hpp"
    "/home/stowy/dev/FunWithVectors/cmake-build-release/_deps/raylib_cpp-src/include/BoundingBox.hpp"
    "/home/stowy/dev/FunWithVectors/cmake-build-release/_deps/raylib_cpp-src/include/Camera2D.hpp"
    "/home/stowy/dev/FunWithVectors/cmake-build-release/_deps/raylib_cpp-src/include/Camera3D.hpp"
    "/home/stowy/dev/FunWithVectors/cmake-build-release/_deps/raylib_cpp-src/include/Color.hpp"
    "/home/stowy/dev/FunWithVectors/cmake-build-release/_deps/raylib_cpp-src/include/Font.hpp"
    "/home/stowy/dev/FunWithVectors/cmake-build-release/_deps/raylib_cpp-src/include/Functions.hpp"
    "/home/stowy/dev/FunWithVectors/cmake-build-release/_deps/raylib_cpp-src/include/Gamepad.hpp"
    "/home/stowy/dev/FunWithVectors/cmake-build-release/_deps/raylib_cpp-src/include/Image.hpp"
    "/home/stowy/dev/FunWithVectors/cmake-build-release/_deps/raylib_cpp-src/include/Material.hpp"
    "/home/stowy/dev/FunWithVectors/cmake-build-release/_deps/raylib_cpp-src/include/Matrix.hpp"
    "/home/stowy/dev/FunWithVectors/cmake-build-release/_deps/raylib_cpp-src/include/Mesh.hpp"
    "/home/stowy/dev/FunWithVectors/cmake-build-release/_deps/raylib_cpp-src/include/Model.hpp"
    "/home/stowy/dev/FunWithVectors/cmake-build-release/_deps/raylib_cpp-src/include/ModelAnimation.hpp"
    "/home/stowy/dev/FunWithVectors/cmake-build-release/_deps/raylib_cpp-src/include/Mouse.hpp"
    "/home/stowy/dev/FunWithVectors/cmake-build-release/_deps/raylib_cpp-src/include/Music.hpp"
    "/home/stowy/dev/FunWithVectors/cmake-build-release/_deps/raylib_cpp-src/include/Ray.hpp"
    "/home/stowy/dev/FunWithVectors/cmake-build-release/_deps/raylib_cpp-src/include/RayCollision.hpp"
    "/home/stowy/dev/FunWithVectors/cmake-build-release/_deps/raylib_cpp-src/include/RaylibException.hpp"
    "/home/stowy/dev/FunWithVectors/cmake-build-release/_deps/raylib_cpp-src/include/raylib-cpp-utils.hpp"
    "/home/stowy/dev/FunWithVectors/cmake-build-release/_deps/raylib_cpp-src/include/raylib-cpp.hpp"
    "/home/stowy/dev/FunWithVectors/cmake-build-release/_deps/raylib_cpp-src/include/raylib.hpp"
    "/home/stowy/dev/FunWithVectors/cmake-build-release/_deps/raylib_cpp-src/include/raymath.hpp"
    "/home/stowy/dev/FunWithVectors/cmake-build-release/_deps/raylib_cpp-src/include/Rectangle.hpp"
    "/home/stowy/dev/FunWithVectors/cmake-build-release/_deps/raylib_cpp-src/include/RenderTexture.hpp"
    "/home/stowy/dev/FunWithVectors/cmake-build-release/_deps/raylib_cpp-src/include/Shader.hpp"
    "/home/stowy/dev/FunWithVectors/cmake-build-release/_deps/raylib_cpp-src/include/Sound.hpp"
    "/home/stowy/dev/FunWithVectors/cmake-build-release/_deps/raylib_cpp-src/include/Text.hpp"
    "/home/stowy/dev/FunWithVectors/cmake-build-release/_deps/raylib_cpp-src/include/Texture.hpp"
    "/home/stowy/dev/FunWithVectors/cmake-build-release/_deps/raylib_cpp-src/include/TextureUnmanaged.hpp"
    "/home/stowy/dev/FunWithVectors/cmake-build-release/_deps/raylib_cpp-src/include/Touch.hpp"
    "/home/stowy/dev/FunWithVectors/cmake-build-release/_deps/raylib_cpp-src/include/Vector2.hpp"
    "/home/stowy/dev/FunWithVectors/cmake-build-release/_deps/raylib_cpp-src/include/Vector3.hpp"
    "/home/stowy/dev/FunWithVectors/cmake-build-release/_deps/raylib_cpp-src/include/Vector4.hpp"
    "/home/stowy/dev/FunWithVectors/cmake-build-release/_deps/raylib_cpp-src/include/VrStereoConfig.hpp"
    "/home/stowy/dev/FunWithVectors/cmake-build-release/_deps/raylib_cpp-src/include/Wave.hpp"
    "/home/stowy/dev/FunWithVectors/cmake-build-release/_deps/raylib_cpp-src/include/Window.hpp"
    )
endif()

