cmake_minimum_required(VERSION 2.8)

#common properties

if (NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Debug CACHE STRING "Choose the type of build, options are: Debug Release" FORCE)
endif ()

set(ROOT "${CMAKE_SOURCE_DIR}/..")
set(OBJ_DIR "${ROOT}/obj/${CMAKE_BUILD_TYPE}")
set(LIB_DIR "${ROOT}/lib/${CMAKE_BUILD_TYPE}")
set(BIN_DIR "${ROOT}/bin/${CMAKE_BUILD_TYPE}")

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${LIB_DIR}")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${LIB_DIR}")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${BIN_DIR}")

set(COMPONENTS pe_lib PeConverter tests samples)

enable_testing()

foreach (COMPONENT ${COMPONENTS})
    add_subdirectory(${COMPONENT})
endforeach ()
