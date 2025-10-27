cmake_minimum_required(VERSION 3.11)

project(tests C)

add_executable(${PROJECT_NAME}
	./main.c
)

find_path(CSTACK_INCLUDE_DIR NAMES cstack.h PATHS /usr/local/include /usr/include)
find_library(CSTACK_LIB NAMES cstack PATHS /usr/local/lib /usr/lib)

target_include_directories(${PROJECT_NAME} PRIVATE ${CSTACK_INCLUDE_DIR} include)
target_link_libraries(${PROJECT_NAME} PRIVATE ${CSTACK_LIB} check)
