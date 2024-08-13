#ifndef COMMAND_H
#define COMMAND_H

typedef struct{
    char* commandString_;
    // commandCode commandCode_;
    int commandID_;
    // int (*executeCommand)(int commandID);
} Command;

Command* getCommand(char* commandString);
void freeCommand(Command* command);

#endif