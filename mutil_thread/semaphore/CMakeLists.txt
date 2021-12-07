set(BIN_NAME semapore)
set(SRC_LIST semaphore.cpp)
#add_executable(${BIN_NAME} ${SRC_LIST})
add_library(${BIN_NAME} SHARED  ${SRC_LIST})

#target_link_libraries(${BIN_NAME} 
