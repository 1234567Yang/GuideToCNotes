#include <stdio.h>

#define STR(x) #x
#define PRINT_INT_VAL(x) printf("%s = %d\n", #x, x)
#define CONNECT(a, b) a ## b

#define PRINT_NUMS_TO_PRODUCT(a, b) do { \
    int product = (a) * (b); \
    for (int i = 0; i < product; i++) { \
        printf("%d\n", i); \
    } \
} while(0)
// 常用小技巧，用 do {} while(0) 圈起来，这样宏编译的时候就不会出现错误
// 如 if(condition) 宏(); else 这里
// 如果没有do while 的话会扩展成 {somefunction()};
// else 部分就会报错

int main(int argc, char *argv[]){
    printf("%s\n", STR(3.14159)); // it became a string
    int temp_int_var = 234;
    PRINT_INT_VAL(temp_int_var);
    printf("the connected value is %lf\n", CONNECT(3.14,15926));
    
    PRINT_NUMS_TO_PRODUCT(4,2);
}
