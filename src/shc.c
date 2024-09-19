#include "shc.h"
#include <stdio.h>
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

// @brief Print info about project
void shc_info(){
    printf("\n--------------------------");
    printf("\nShell-C");
    printf("\nVersion - %s", shc_version);
    printf("\nAuthor - %s", shc_author);
    printf("\n--------------------------");
}

// @brief Function to get string containing command, flags, arguments, etc, finished by clicking ENTER (10 value)
// @param destination pointer to destination, where the string will be written with NULL at the end
// @returns 0 if proper command, meaning finished by clicking enter, -1 otherwise
int shc_readLine(char* destination){
    int c = getchar();
    for(int i = 0; i < SHC_BUFFER_SIZE; i++){
        *destination = c;
        if(*destination == 10){
            *destination = '\0';
            return 0;
        }
        destination++;
        c = getchar();
    }
    return -1;
}

// @brief Waiting for user to type command in terminal
// @param buffer buffer to store command
int shc_waitForInput(char* buffer){
    printf(shc_terminal_header);
    if(shc_readLine(buffer) == 0){
        // printf("Succesfully readed");
        return 0;
    }
    else{
        printf("Error during reading cmd line");
        return -1;
    }
}


// @brief Main loop of Shell
int shc_loop(){
    int pid_nr = 0;
    int processNumbers = 0;
    Command* shc_cmnd = getCommand("shc");
    Process* shc_Process = createProcess(shc_cmnd,pid_nr + 1,0);
    if(shc_Process == NULL){
        exit(0);
    }
    else{
        processNumbers++;
        pid_nr++;
    }

    while(1){
        char* shc_commandLineBuffer = malloc(SHC_BUFFER_SIZE * sizeof(char));
        if(shc_commandLineBuffer == NULL){
            return -1;
        }
        if(shc_waitForInput(shc_commandLineBuffer) == -1){
            return -1;
        }
        Tokens* currTokens = findTokens(shc_commandLineBuffer, delimiter);
        if(currTokens == NULL){
            return -1;
        }
        Command* cmnd = getCommand(currTokens->tokens[0]); // for now command only one word command and then flags (todo)
        if(cmnd){
            cmnd->handleCommand = findCommandHandler(cmnd->commandID_);
            processNumbers++;
            pid_nr++;
            Process* newProcess = createProcess(cmnd,pid_nr,shc_Process->pid);
            int cmdResult = newProcess->command->handleCommand();
            if(cmdResult == 0){
                // printf("\nProcess handled correctly, command executed");
                processNumbers--;
            }
            else{
                // printf("\nError during execution of process");
            }
            killProcess(newProcess);
            freeCommand(cmnd);
        }
        else{
            printf("\nInvalid command");
        }

        freeTokens(currTokens);
        free(shc_commandLineBuffer);
    }
}
