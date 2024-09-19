#include <stdlib.h>
#include <string.h>
#include "command.h"
#include "commandHandlers/command_handlers.h"

#define SHC_COMMANDS_NUMBER 3

char* shc_commandsByIDS[SHC_COMMANDS_NUMBER] = {"shc","pwd","exit"};

// @return Pointer to Command
Command* getCommand(char* commandString){
    for(int i = 0; i < SHC_COMMANDS_NUMBER; i++){
        if(strcmp(shc_commandsByIDS[i],commandString) == 0){
            Command* result = malloc(sizeof(Command));
            result->commandID_ = i;
            result->commandString_ = shc_commandsByIDS[i];
            return result;
        }
    }
    return NULL;
}

// @brief deletes Command
void freeCommand(Command* command){
    if(command){
        free(command);
    }
}

intFvoidPointer findCommandHandler(int commandID_){
    // few commands for now so simple switch case, in the future if many commands some faster searching maybe
    switch (commandID_){
        case 0:
            return handleCommand_shc;
            break;
        case 1:
            return handleCommand_pwd;
            break;
        case 2:
            return handleCommand_exit;
            break;
        default:
            return NULL;
            break;
    }
}