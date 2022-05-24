cmake_minimum_required(VERSION 3.0)
project(AttachPtrTest)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

aux_source_directory(. DIR_SRCS)

message(STATUS "CMAKE_SOURCE_DIR=${CMAKE_SOURCE_DIR}")

include_directories(
	${CMAKE_SOURCE_DIR}/AttachPtr
)

file(GLOB DIR_SRCS_HEADER *.h)
file(GLOB DIR_SRCS_HEADER *.hpp)

add_executable(AttachPtrTest ${DIR_SRCS} ${DIR_SRCS_HEADER})