#include<stdio.h>
#include<stdlib.h>
#include "input.h"
#include "parser.h"
#include "launch.h"


//make shell.h later after the loop is finisheds
void lsh_loop(void){
    char *line;
    char **args;
    int status;

    do{
        printf(">");
        line = lsh_read_line();
        args = lsh_parse_line(line);
        // add launch and execition later

    } while (status);
    
}