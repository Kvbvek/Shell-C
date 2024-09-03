#include <stdio.h>
#include <stdlib.h>
#include "exit_handler.h"

int handleCommand_exit(){
    printf("\nClosing...");
    exit(0);
    return 0;
}