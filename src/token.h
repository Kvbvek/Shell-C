#ifndef TOKEN_H
#define TOKEN_H

typedef struct{
    int numTokens;
    char** tokens; // Array of pointers to tokens
} Tokens;

Tokens* findTokens(const char* str, const char* delimiter);
void freeTokens(Tokens* tokens);

#endif