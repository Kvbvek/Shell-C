#include <stdio.h>
#include <dirent.h>
#include "pwd_handler.h"

#define SHC_BUFFER_SIZE 1024

// @brief Function to get current path
// @returns Pointer to string containing current path
char* getCurrentPath(){
    char buffer[SHC_BUFFER_SIZE];
    char* pPath = NULL;
    if(getcwd(buffer, sizeof(buffer)) != NULL){
        pPath = buffer;
    }
    return pPath;
}

int handleCommand_pwd(){
    printf("\n%s",getCurrentPath());
    return 0;
}

