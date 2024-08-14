#include "shc.h"
#include <stdio.h>
// #include <dirent.h>
#include <stdlib.h>
// #include <string.h>

#include "token.h"
#include "command.h"
#include "process.h"

#define SHC_BUFFER_SIZE 1024

const char* delimiter = " ";
const static char* shc_version = "0.2";
const static char* shc_author = "Jakub Brzazgacz";

const char* shc_terminal_header = "\nshc> $ ";

int processNumbers;

// @brief Print info about project
void shc_info(){
    printf("\n--------------------------");
    printf("\nShell-C");
    printf("\nVersion - %s", shc_version);
    printf("\nAuthor - %s", shc_author);
    printf("\n--------------------------");
}

// @brief Function to get current path
// @returns Pointer to string containing current path
// char* shc_getCurrentPath(){
//     char buffer[SHC_BUFFER_SIZE];
//     char* pPath = NULL;
//     if(getcwd(buffer, sizeof(buffer)) != NULL){
//         pPath = buffer;
//     }
//     return pPath;
// }

// @brief Function to get string containing command, flags, arguments, etc, finished by clicking ENTER
// @param destination pointer to destination, where the string will be written with NULL at the end
// @returns 1 if proper command, meaning finished by clicking enter, -1 otherwise
int shc_readLine(char* destination){
    int c = getchar();
    for(int i = 0; i < SHC_BUFFER_SIZE; i++){
        *destination = c;
        if(*destination == 10){
            *destination = '\0';
            return 1;
        }
        destination++;
        c = getchar();
    }
    return -1;
}

// @brief Waiting for user to type command in terminal
// @param buffer buffer to store command
void shc_waitForInput(char* buffer){
    printf(shc_terminal_header);
    if(shc_readLine(buffer) == 1){
        // todo maybe success or smth
    }
    else{
        printf("\nError during reading cmd line");
    }
}

// @brief Main loop of Shell
void shc_loop(){
    char* shc_commandLineBuffer = malloc(SHC_BUFFER_SIZE * sizeof(char));
    shc_waitForInput(shc_commandLineBuffer);

    Tokens* currTokens = findTokens(shc_commandLineBuffer, delimiter);
    // printf("\n Number of tokens - %d",currTokens->numTokens);
    // char** tok = currTokens->tokens;
    // for(int i = 0; i < currTokens->numTokens; i++){
    //     printf("\nToken nr %d - %s", i, *tok);
    //     tok++;
    // }
    Command* cmnd = getCommand(currTokens->tokens[0]);
    
    // printf("%d", cmnd->commandID_);
    cmnd->handleCommand = findCommandHandler(cmnd->commandID_);
    if(cmnd){
        processNumbers++;
        Process* newProcess = createProcess(cmnd,processNumbers,0);

        printf("\nCommand ID - %d", cmnd->commandID_);
        printf("\nString - %s", cmnd->commandString_);
        int cmdResult = newProcess->command->handleCommand();
        printf("\nProcess PID - %d", newProcess->pid);
        if(cmdResult == 1){
            printf("\nProcess executed correctly");
        }
        else{
            printf("\nError during execution of process");
        }
        free(cmnd);
        killProcess(newProcess);
    }
    else{
        printf("\nInvalid command");
    }

    free(shc_commandLineBuffer);
    freeTokens(currTokens);
}
