cmake_minimum_required(VERSION 3.11)
project(exampleint C)

add_library(cvector STATIC IMPORTED)
set_target_properties(cvector PROPERTIES
  IMPORTED_LOCATION "${CMAKE_SOURCE_DIR}/../../build/lib/libcvector.a"
  INTERFACE_INCLUDE_DIRECTORIES "${CMAKE_SOURCE_DIR}/../../include"
)

add_executable(${PROJECT_NAME}
  ./main.c
  ./src/cvec_int.c
)

target_include_directories(${PROJECT_NAME} PRIVATE include)

target_link_libraries(${PROJECT_NAME} PRIVATE cvector)
