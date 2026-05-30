#include <stdio.h>

int func1(){
    printf("Func 1 \n");
    return 1;
}

int func2(){
    printf("Func 2 \n");
    return 1;
}

int main(void){
    if(func1() == 1 || func2() == 1){
        printf("First if\n");
    }
    printf("\n\n\n-----------\n\n\n");
    if(func1() == 1 | func2() == 1){
        printf("Second if\n");
    }

    unsigned char bin = 0b000011;
    bin = bin << 2;
    printf("%u\n\n",bin);
}
