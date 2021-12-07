set(SUB_DIR_SEQ 
condition 
mutexdemo 
semaphore
)
#SUBDIRS
foreach(item ${SUB_DIR_SEQ})
    add_subdirectory(${item}) 
endforeach()
