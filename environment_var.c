#include <stdio.h>
#include <stdlib.h>

// The environ array is NULL-terminated.
extern char **environ;

int main(int argc, char *args[]){
    //printf("The envireon is: \n%s\n", environ);
    for(char** e = environ; *e != NULL; e++){
        printf("%s\n\n", *e);
    }
}