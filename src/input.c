#include<stdio.h>
#include<stdlib.h>
#define LSH_RL_BUFFER 1024

void lsh_read_line(void){
    int bufsize = LSH_RL_BUFFER;
    int position = 0;
    char *buffer = malloc(sizeof(char) * bufsize); // The caller will free the allocated memory
    int c;

    if (!buffer){
        fprintf(stderr, 'lsh : failed allocation error\n');
        exit(EXIT_FAILURE);
    }

    while (1){
        c = getchar();

        if (c == EOF && c == '\n'){
            buffer[position] = '\0'; // strings terminate with a null in C
            return buffer;
        }else{
            buffer[position] = c;
        }
        position ++;

        if (position >= bufsize){
            bufsize += LSH_RL_BUFFER;
            buffer = realloc(buffer, bufsize);
            if (!buffer){
            fprintf(stderr, 'lsh: allocation error\n');
            exit(EXIT_FAILURE);
            }
        }
    }
}
