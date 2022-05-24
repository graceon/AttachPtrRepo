cmake_minimum_required (VERSION 3.0)
project ("AttachPtrRepo")
set (VERSION_MAJOR 0)
set (VERSION_MINOR 1)

Message(STATUS "CMAKE_CURRENT_SOURCE_DIR = " ${CMAKE_CURRENT_SOURCE_DIR})
Message(STATUS "CMAKE_SYSTEM = " ${CMAKE_SYSTEM})
Message(STATUS "CMAKE_SYSTEM_NAME = " ${CMAKE_SYSTEM_NAME})
Message(STATUS "CMAKE_SYSTEM_VERSION = " ${CMAKE_SYSTEM_VERSION})

if(NOT MSVC AND EXISTS "/usr/local/gcc/bin/gcc")
set(CROSS_TOOLCHAIN_PREFIX "/usr/local/gcc/bin/")
set(CMAKE_C_COMPILER "${CROSS_TOOLCHAIN_PREFIX}gcc")
set(CMAKE_CXX_COMPILER "${CROSS_TOOLCHAIN_PREFIX}g++")
endif(NOT MSVC AND EXISTS "/usr/local/gcc/bin/gcc")

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 11)


if(NOT MSVC)
set(CMAKE_BUILD_TYPE Debug)
else(NOT MSVC)
set(CMAKE_BUILD_TYPE Release)
endif(NOT MSVC)

set(CMAKE_BUILD_PLATFORM X86) #ARM #X86

if(WIN32)
    add_compile_options("$<$<C_COMPILER_ID:MSVC>:/utf-8>")
    add_compile_options("$<$<CXX_COMPILER_ID:MSVC>:/utf-8>")
	add_compile_options("$<$<C_COMPILER_ID:MSVC>:/bigobj>")
    add_compile_options("$<$<CXX_COMPILER_ID:MSVC>:/bigobj>")
endif()






set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/obj)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin)

add_subdirectory(AttachPtrTest)