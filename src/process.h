#ifndef PROCESS_H
#define PROCESS_H

#include "command.h"

typedef struct{
    Command* command;
    int pid;
    int ppid;
} Process;

void killProcess(Process* processToKill);
Process* createProcess(Command* command_, int pid_, int ppid_);

#endif