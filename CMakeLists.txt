cmake_minimum_required(VERSION 3.0.0)
project(sort VERSION 0.1.0)

include(CTest)
enable_testing()

include_directories(include)
aux_source_directory(src dir)

add_executable(sort ${dir})

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
