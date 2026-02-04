#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *args[]){
    char *path = getenv("PATH");
    printf("The path is: \n%s\n", path);
}