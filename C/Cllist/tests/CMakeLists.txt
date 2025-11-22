cmake_minimum_required(VERSION 3.11)

project(tests C)

add_executable(${PROJECT_NAME}
	./main.c
)

find_path(CLLIST_INCLUDE_DIR NAMES cllist.h PATHS /usr/local/include /usr/include)
find_library(CLLIST_LIB NAMES cllist PATHS /usr/local/lib /usr/lib)

target_include_directories(${PROJECT_NAME} PRIVATE ${CLLIST_INCLUDE_DIR} include)
target_link_libraries(${PROJECT_NAME} PRIVATE ${CLLIST_LIB} check)
