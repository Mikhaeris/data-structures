cmake_minimum_required(VERSION 3.11)

project(Cvector)

add_executable(${PROJECT_NAME}
	./main.c
	./Cvector.c
)

#target_include_directories(${PROJECT_NAME} PRIVATE include)
