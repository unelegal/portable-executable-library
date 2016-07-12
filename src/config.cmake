project(${PROJECT})

if (CMAKE_CXX_COMPILER_ID MATCHES "Clang")
    set(CMAKE_COMPILER_IS_CLANGXX 1)
endif ()

if(MSVC)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /W4 /WX")
elseif(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_COMPILER_IS_CLANGXX)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x -Wall -Werror -fstrict-aliasing -pedantic-errors -pedantic")
endif()

if(NOT DEFINED HEADERS)
file(GLOB HEADERS ${${PROJECT}_SOURCE_DIR}/*.h)
endif ()

if(NOT DEFINED SOURCES)
file(GLOB SOURCES ${${PROJECT}_SOURCE_DIR}/*.cpp)
endif ()

source_group("Header Files" FILES ${HEADERS})
source_group("Source Files" FILES ${SOURCES})

