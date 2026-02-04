#include <stdio.h>

int main(void){

    // void* 类型很有趣，因为它可以从任何指针类型转换或转换到任何指针类型。
    int x = 10;
    void *p = &x;  // &x is type int*, but we store it in a void*
    int *q = p;    // p is void*, but we store it in an int*

    // void* 是一种通用指针，可以指向任何类型的数据，但它有一个限制：不能直接解引用。因为编译器不知道 void* 指向的数据是什么类型、占多少字节。
    // 所以要读取 void* 指向的值，必须先把它转换（cast）成具体的指针类型。


    // 错误示范（无法编译）：
    // printf("%d\n", *p);  // 错误！不能直接解引用 void*
    printf("通过 cast 解引用 void*: %d\n", *((int*)p));

}