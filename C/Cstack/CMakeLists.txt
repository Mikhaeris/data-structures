cmake_minimum_required(VERSION 3.11)
project(cstack C)

if(CMAKE_INSTALL_PREFIX_INITIALIZED_TO_DEFAULT)
  set(CMAKE_INSTALL_PREFIX "/usr/local" CACHE PATH "Install path" FORCE)
endif()

option(BUILD_SHARED_LIBS "Build shared libraries" ON)

add_library(${PROJECT_NAME}
  ./source/cstack.c
)

target_include_directories(${PROJECT_NAME} PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include>
)

install(TARGETS ${PROJECT_NAME}
  LIBRARY DESTINATION lib
  ARCHIVE DESTINATION lib
  RUNTIME DESTINATION bin
)

install(FILES include/cstack.h DESTINATION include)
