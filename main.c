// C Implementation of Shell
// Author - Jakub Brzazgacz
// Last modified 09.08.2024

#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>
// #include <string.h>

#include "src/token.h"
#include "src/command.h"

#define SHC_BUFFER_SIZE 1024
#define DELIMITER ' '

const static char* shc_version = "0.2";
const static char* shc_author = "Jakub Brzazgacz";

const char* shc_terminal_header = "\nshc> $ ";

// ----------------------------- //
// static int processNumbers;

typedef struct{
    Command* command;
    int pid;
    int ppid;
} Process;

Process* createProcess(Command* command_, int pid_, int ppid_){
    if(command_){
        Process* process = malloc(sizeof(Process));
        process->ppid = ppid_;
        process->pid = pid_;
        process->command = command_;
        return process;
    }
    else{
        return NULL;
    }
}

void shc_init(){
    // shc_createProcess()
}

void killProcess(Process* processToKill){
    free(processToKill);
}

// void shc_executeCommand(Command* commandToExecute){
//     // pointer to function ?? as commands have different execution actions
// }
// ----------------------------- //

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
char* shc_getCurrentPath(){
    char buffer[SHC_BUFFER_SIZE];
    char* pPath = NULL;
    if(getcwd(buffer, sizeof(buffer)) != NULL){
        pPath = buffer;
    }
    return pPath;
}

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
        printf("good command");
    }
    else{
        printf("bad command");
    }
}

// @brief Main loop of Shell
void shc_loop(){
    char* shc_commandLineBuffer = malloc(SHC_BUFFER_SIZE * sizeof(char));
    shc_waitForCommand(shc_commandLineBuffer);
    free(shc_commandLineBuffer);
}

int main(){
    shc_info();
    shc_loop();
}
