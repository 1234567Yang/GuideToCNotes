#include <stdio.h>

int main(int argc, char *argv[])
{
    printf("argv[argc] == NULL is always true: %d\n\n", argv[argc] == NULL);
    FILE *f = fopen("args.txt", "a");

    for (int i = 0; i < argc; i++) {
        fprintf(f, "args %d is %s\n\n", i, argv[i]);
        
        printf("arg %d: %s\n", i, argv[i]);
    }
}