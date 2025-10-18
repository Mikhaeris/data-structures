cmake_minimum_required(VERSION 3.11)
project(clist C)

if(CMAKE_INSTALL_PREFIX_INITIALIZED_TO_DEFAULT)
  set(CMAKE_INSTALL_PREFIX "/usr/local" CACHE PATH "Install path" FORCE)
endif()

option(BUILD_SHARED_LIBS "Build shared libraries" ON)

add_library(clist
  ./source/clist.c
)

target_include_directories(clist PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include>
)

install(TARGETS clist
  LIBRARY DESTINATION lib
  ARCHIVE DESTINATION lib
  RUNTIME DESTINATION bin
)

install(FILES include/clist.h DESTINATION include)
