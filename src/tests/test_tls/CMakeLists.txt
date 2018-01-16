cmake_minimum_required(VERSION 2.8)

set(PROJECT test_tls)

include (${pe_lib_root_SOURCE_DIR}/config.cmake)

add_executable(${PROJECT} ${HEADERS} ${SOURCES})

target_include_directories(${PROJECT} PRIVATE ${pe_lib_SOURCE_DIR} ${pe_lib_root_SOURCE_DIR}/tests/)
    
target_link_libraries(${PROJECT} PRIVATE pe_lib)

