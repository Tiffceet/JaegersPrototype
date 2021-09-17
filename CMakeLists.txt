cmake_minimum_required(VERSION 3.0.0)
project(JaegarPrototype VERSION 0.1.0)

SET(MSVC_FREEGLUT "freeglutd")
SET(MINGW_FREEGLUT "libfreeglut")

include(CTest)
enable_testing()

add_executable(JaegarPrototype main.cpp camera.cpp lighting.cpp primitives.cpp texture.cpp body.cpp _hand.cpp _leg.cpp head.cpp animation.cpp spawnable_object.cpp)
target_include_directories(JaegarPrototype PUBLIC "include")
target_include_directories(JaegarPrototype PUBLIC "header")
target_link_directories(JaegarPrototype PUBLIC "lib")


if (CMAKE_CXX_COMPILER_ID MATCHES "MSVC")
    target_link_libraries(JaegarPrototype "opengl32" ${MSVC_FREEGLUT} "glu32")
endif()

if (CMAKE_CXX_COMPILER_ID MATCHES "GNU")
    target_link_libraries(JaegarPrototype "opengl32" ${MINGW_FREEGLUT} "glu32")
    SET(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -std=gnu++11")
endif()

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
