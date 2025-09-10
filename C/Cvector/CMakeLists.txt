cmake_minimum_required(VERSION 3.11)

project(cvector C)

option(BUILD_SHARED_LIBS "Build shared libraries" OFF)

add_library(cvector
	source/Cvector.c
)
