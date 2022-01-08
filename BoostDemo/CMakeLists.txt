#cmake_minimum_required(VERSION 3.0)

#project(BoostDemo)

#set(CMAKE_CXX_STANDARD 11)
#set(CMAKE_CXX_EXTENSIONS ON)
#set(CMAKE_CXX_STANDARD_REQUIRED ON)

#boost
if(WIN32)
  set(BOOST_ROOT "C:/Boost")
endif()

find_package(Boost REQUIRED COMPONENTS 
filesystem
)
#运行完find以后可以得到以下变量
#Boost_FOUND            - 如果找到了所需的库就设为true
#Boost_INCLUDE_DIRS     - Boost头文件搜索路径
#Boost_LIBRARY_DIRS     - Boost库的链接路径
#Boost_LIBRARIES        - Boost库名，用于链接到目标程序
#Boost_VERSION          - 从boost/version.hpp文件获取的版本号
#Boost_LIB_VERSION      - 某个库的版本

if(Boost_FOUND)
    message( STATUS "Boost_INCLUDE_DIRS = ${Boost_INCLUDE_DIRS}.")
    message( STATUS "Boost_LIBRARIES = ${Boost_LIBRARIES}.")
    message( STATUS "Boost_LIB_VERSION = ${Boost_LIB_VERSION}.")
endif()
#set(Boost_INCLUDE_DIRS ${BOOST_ROOT}/include)
#set(Boost_LIBRARY_DIR ${BOOST_ROOT}/lib) 
include_directories(${Boost_INCLUDE_DIRS})
#link_directories(${Boost_LIBRARY_DIR})

#set(Protobuf_ROOT "C:/app/google/cmake")
#find_package(Protobuf)
#if(Protobuf_FOUND)
#message(STATUS "Protobuf Include Dir:${Protobuf_INCLUDE_DIRS}")
#endif()
#include_directories(${Protobuf_INCLUDE_DIRS})
#include_directories("C:/app/google/include")
#link_directories("C:/app/google/lib")

add_executable(${PROJECT_NAME} boostdemo.cpp)

target_link_libraries(${PROJECT_NAME} 
PUBLIC
#Boost::filesystem
#libprotobuf.lib
#libprotobuf-lite.lib
#libprotoc.lib
#${LIBRARY_OUTPUT_PATH}/***.lib
${Boost_LIBRARIES}
)
