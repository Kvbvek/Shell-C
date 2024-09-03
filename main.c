// C Implementation of Shell
// Author - Jakub Brzazgacz
// Last modified 03.09.2024

#include <stdio.h>
// #include <dirent.h>
#include "src/shc.h"

int main(){
    shc_info();
    if(shc_loop() == -1){
        printf("\nError in shc_loop");
        return 0;
    }
    return 0;
}
