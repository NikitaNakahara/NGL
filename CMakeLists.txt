cmake_minimum_required(VERSION 3.12)

set(PROJECT_NAME NGL)

set(INCLUDES include/NGL/ngl.hpp)
set(SRC src/ngl.cpp)

add_library(${PROJECT_NAME} STATIC
    ${INCLUDES}
    ${SRC}
)
include_directories(${CMAKE_INCLUDE_SOURCE_DIR}/include)

target_link_libraries(${PROJECT_NAME} X11)