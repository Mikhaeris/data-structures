cmake_minimum_required(VERSION 3.11)
project(example C)

add_executable(${PROJECT_NAME}
  ./main.c
)

find_path(CVECTOR_INCLUDE_DIR NAMES clist.h PATHS /usr/local/include /usr/include)
find_library(CVECTOR_LIB NAMES clist PATHS /usr/local/lib /usr/lib)

target_include_directories(${PROJECT_NAME} PRIVATE ${CVECTOR_INCLUDE_DIR} include)
target_link_libraries(${PROJECT_NAME} PRIVATE ${CVECTOR_LIB})
