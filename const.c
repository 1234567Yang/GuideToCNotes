#include <stdio.h>


void foo(const int x)
{
    printf("%d\n", x + 30);  // OK, doesn't modify "x"
}

// const 修饰它左边的东西（除非它在最左边，才修饰右边）

int main(void){
    int x[] = {10, 20};
    const int *p = x;  // const 修饰 int
    // int const *p;  // Can't modify what p points to, just like the previous line
    // const 和 int 可以互换
    p++;  // We can modify p, no problem
    // *p = 30; // Compiler error! Can't change what it points to



    int *const p1 = x; // const 在 * 后面，修饰 *
    // &x 是 int (*)[2]指向整个数组的指针
    printf("%d\n", *p1);


    const int *const p2 = x+1;
    printf("%d\n", *p2);

    /*
    p          *p           **p
    ┌─────┐    ┌─────┐      ┌─────┐
    │  ●──┼───>│  ●──┼─────>│ 'A' │
    └─────┘    └─────┘      └─────┘
    char**     char*        char
    */
    char **doublep;
    // 靠近变量名的：说明它是个指针
    // 最左边的：二级指针指向
    doublep++;     // OK!
    (*doublep)++;  // OK!

    char **const doublep2;
    // doublep2++;     // Error!
    (*doublep2)++;  // OK!

}