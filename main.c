// C Implementation of Shell
// Author - Jakub Brzazgacz
// Last modified 09.08.2024

#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>
#include <string.h>

#define SHC_BUFFER_SIZE 1024

const static char* shc_version = "0.1";
const static char* shc_author = "Jakub Brzazgacz";

const char* shc_terminal_header = "\nshc> ";

struct Command{
    char commandString[SHC_BUFFER_SIZE];
    char* commands[1];
};

enum commandID{invald,pwd};

enum commandID findCommand(){

}

char* tokenToString(char* commandString){
    char cmd[10];
    char* pCmd = cmd;
    for(int i = 0; i < strlen(commandString) + 1; i++){
        cmd[i] = *commandString;
        if(*commandString == ' '){
            cmd[i] = '\0';
            return pCmd;
        }
        commandString++;
    }
    return NULL;
}

// @brief Function print info about project
void shc_info(){
    printf("\n//////////////////////////");
    printf("\nShell written in C");
    printf("\nVersion - %s", shc_version);
    printf("\nAuthor - %s", shc_author);
    printf("\n//////////////////////////");
}

// @brief Function to get current path
// @returns Pointer to string containing full path
char* shc_getCurrentPath(){
    char buffer[SHC_BUFFER_SIZE];
    char *pPath = NULL;
    if(getcwd(buffer, sizeof(buffer)) != NULL){
        pPath = buffer;
    }
    return pPath;
}

void shc_putPath(){
    printf(shc_terminal_header);
    printf("%s>",shc_getCurrentPath());
}

// @brief Function to get current full string containing command etc, finished by ENTER
// @param destination pointer to destination, where the string will be written
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

// @brief Main loop of Shell
void shc_loop(){
    struct Command *command = (struct Command *)malloc(sizeof(struct Command));
    int properCommand = shc_readLine(command->commandString);
    if(properCommand == 1){
        puts("executing process");
    }
    else{
        puts("invalid command");
    }
    free(command);
}

int main(){
    shc_info();
    shc_loop();
}
