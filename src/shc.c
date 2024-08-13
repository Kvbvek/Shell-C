#include "shc.h"
#include <stdio.h>
// #include <dirent.h>
#include <stdlib.h>
// #include <string.h>

#include "token.h"
#include "command.h"

#define SHC_BUFFER_SIZE 1024

const char* delimiter = " ";
const static char* shc_version = "0.2";
const static char* shc_author = "Jakub Brzazgacz";

const char* shc_terminal_header = "\nshc> $ ";

// @brief Main loop of Shell
void shc_loop(){
    char* shc_commandLineBuffer = malloc(SHC_BUFFER_SIZE * sizeof(char));
    shc_waitForCommand(shc_commandLineBuffer);
    Tokens* currTokens = findTokens(shc_commandLineBuffer, delimiter);
    printf("\n%d",currTokens->numTokens);
    char** tok = currTokens->tokens;
    for(int i = 0; i < currTokens->numTokens; i++){
        printf("\n%s",*tok);
        tok++;
    }
    Command* cmnd = getCommand(*(currTokens->tokens));
    if(cmnd){
        printf("\n%d", cmnd->commandID_);
        printf("\n%s", cmnd->commandString_);
    }
    else{
        printf("invalid command");
    }
    free(shc_commandLineBuffer);
    freeCommand(cmnd);
    freeTokens(currTokens);
}

// @brief Print info about project
void shc_info(){
    printf("\n--------------------------");
    printf("\nShell implemented in C");
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

void shc_waitForCommand(char* buffer){
    printf(shc_terminal_header);
    if(shc_readLine(buffer) == 1){
        printf("cmd line read properly");
    }
    else{
        printf("error during reading cmd line");
    }
}