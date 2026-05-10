#include <stdio.h>
#include <stddef.h>

int main(void){
    int cats[100];
    int *f = cats + 20;
    int * g = cats + 60;
    
    ptrdiff_t diff = g - f;

    printf("As decimal: %td\nAs hex: %tX\n", diff, diff);

}
