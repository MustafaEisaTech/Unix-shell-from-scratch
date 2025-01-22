#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "input.h"
#define LSH_PL_BUFFER 64
#define LSH_PL_DELIM " \t\r\n\a"

char **lsh_parse_line(char *line){
    int buffsize = LSH_PL_BUFFER;
    char *token; //points to an array
    char **tokens = malloc(sizeof(char*) * buffsize); // points to a pointer that points to an array 
    int position = 0;

    if (!tokens){
        fprintf(stderr, "lsh : allocation failure\n");
        exit(EXIT_FAILURE);
    }
    token = strtok(line, LSH_PL_DELIM);

    while (token != NULL){
        tokens[position] = token;
        position ++;

        if (position >= buffsize){
            buffsize += LSH_PL_BUFFER;
            tokens = realloc(tokens, buffsize);
            if (!tokens){
                fprintf(stderr,"lsh : allocation failure\n");
                exit(EXIT_FAILURE);
            }
        }
        token = strtok(NULL, LSH_PL_DELIM); //NULL to continue tokenizing the same input string 
    }
    tokens[position] = NULL; // the end of a string array has to be NULL else undefined behavior 
    return tokens;
}