cmake_minimum_required(VERSION 3.0)

project(smartptr)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

#boost
#set(BOOST_ROOT "C:/Boost")
#find_package(Boost REQUIRED COMPONENTS filesystem)
#if(Boost_FOUND)
#message(STATUS "Boost Include Dir:${Boost_INCLUDE_DIRS}")
#endif()
#include_directories(${Boost_INCLUDE_DIRS})


#set(Protobuf_ROOT "C:/app/google/cmake")
#find_package(Protobuf)
#if(Protobuf_FOUND)
#message(STATUS "Protobuf Include Dir:${Protobuf_INCLUDE_DIRS}")
#endif()
#include_directories(${Protobuf_INCLUDE_DIRS})
#include_directories("C:/app/google/include")
#link_directories("C:/app/google/lib")

add_executable(${PROJECT_NAME} smartptr.cpp)

target_link_libraries(${PROJECT_NAME} 
#PUBLIC
#Boost::filesystem
#libprotobuf.lib
#libprotobuf-lite.lib
#libprotoc.lib
)
