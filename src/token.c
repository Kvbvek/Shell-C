#include "token.h"
#include <string.h>
#include <stdlib.h>

Tokens* findTokens(const char* str, const char* delimiter){
    char *strCopy = strdup(str);
    if(!strCopy){
        return NULL;
    }

    int count = 0;
    char *token;
    
    char *temp = strdup(str);
    token = strtok(temp, delimiter);
    while(token != NULL){
        count++;
        token = strtok(NULL, delimiter);
    }
    free(temp);

    Tokens *result = malloc(sizeof(Tokens));
    if(!result){
        free(strCopy);
        return NULL;
    }

    result->numTokens = count;
    result->tokens = malloc(count * sizeof(char*));
    if(!result->tokens){
        free(result);
        free(strCopy);
        return NULL;
    }

    count = 0;
    token = strtok(strCopy, delimiter);
    while(token != NULL){
        result->tokens[count++] = token;
        token = strtok(NULL, delimiter);
    }

    return result;
}

void freeTokens(Tokens* tokens){
    if(tokens){
        free(tokens->tokens);
        free(tokens);
    }
}
