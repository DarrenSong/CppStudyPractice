cmake_minimum_required(VERSION 3.0)

project(cpptest)
set(CMAKE_BUILD_TYPE )
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
message(STATUS Build Type:${CMAKE_BUILD_TYPE})
# set exe output path
#set(EXECUTABLE_OUTPUT_PATH ${CMAKE_CURRENT_SOURCE_DIR}/build/bin)
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)
set(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/lib)

#set build sub dir
# if you do not build some sub folders,just comment them.
set(SUB_DIR_SEQ 
BoostDemo 
mutil_thread 
smartptr
memorymgr
)

foreach(item ${SUB_DIR_SEQ})
    add_subdirectory(${item}) 
endforeach()
