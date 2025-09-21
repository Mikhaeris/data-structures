cmake_minimum_required(VERSION 3.11)
project(cvector C)

if(CMAKE_INSTALL_PREFIX_INITIALIZED_TO_DEFAULT)
  set(CMAKE_INSTALL_PREFIX "/usr/local" CACHE PATH "Install path" FORCE)
endif()

option(BUILD_SHARED_LIBS "Build shared libraries" ON)

add_library(cvector
  source/Cvector.c
)

target_include_directories(cvector PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include>
)

install(TARGETS cvector
  LIBRARY DESTINATION lib
  ARCHIVE DESTINATION lib
  RUNTIME DESTINATION bin
)

install(FILES include/Cvector.h DESTINATION include)
