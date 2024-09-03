#ifndef COMMAND_H
#define COMMAND_H

typedef int (*intFvoidPointer)();

typedef struct{
    char* commandString_;
    int commandID_;
    intFvoidPointer handleCommand;
} Command;

Command* getCommand(char* commandString);
void freeCommand(Command* command);
intFvoidPointer findCommandHandler(int commandID_);

#endif