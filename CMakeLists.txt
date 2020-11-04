
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ../out/)

cmake_minimum_required(VERSION 3.13)

project(shiki_api)

set(SOURCE_LIB src/shiki_api.cpp)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_library(shiki_api STATIC ${SOURCE_LIB})

find_package(CURL REQUIRED)
include_directories(${CURL_INCLUDE_DIR})

target_include_directories(shiki_api PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_link_libraries(shiki_api ${CURL_LIBRARIES})

