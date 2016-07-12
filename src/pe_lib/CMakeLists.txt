cmake_minimum_required(VERSION 2.8)

set(PROJECT pe_lib)
   
include (${CMAKE_SOURCE_DIR}/config.cmake)

add_library(${PROJECT} STATIC ${HEADERS} ${SOURCES})
