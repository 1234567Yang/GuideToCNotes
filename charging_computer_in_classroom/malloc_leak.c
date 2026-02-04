#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
    int *int_arr_len10 = malloc(sizeof(int)*10);
    int_arr_len10[0] = 3;
    printf("%d\n", int_arr_len10[0]);
}
