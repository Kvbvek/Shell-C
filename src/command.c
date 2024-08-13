#include <stdlib.h>
#include <string.h>
#include "command.h"

#define SHC_COMMANDS_NUMBER 4

char* shc_commands[SHC_COMMANDS_NUMBER] = {"invalid","shc","pwd","exit"};

// @return Pointer to Command
Command* getCommand(char* commandString){
    char** currCommand = shc_commands;
    for(int i = 0; i < SHC_COMMANDS_NUMBER; i++){
        if(strcmp(*currCommand,commandString) == 0){
            Command* result = malloc(sizeof(Command));
            result->commandID_ = i;
            result->commandString_ = *currCommand;
            return result;
        }
        currCommand++;
    }
    return NULL;
}

// @brief deletes Command
void freeCommand(Command* command){
    if(command){
        free(command);
    }
}