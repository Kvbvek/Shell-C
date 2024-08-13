#include "process.h"
#include <stdlib.h>

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

void killProcess(Process* processToKill){
    if(processToKill){
        free(processToKill);
    }
}