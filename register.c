#include <stdio.h>

int main(void)
{
    register int a; // Make "a" as fast to use as possible.

    for (a = 0; a < 10; a++)
        printf("%d\n", a);
    
    // int *p = &a;    // COMPILER ERROR! Can't take address of a register


    register int arr[] = {11, 22, 33, 44, 55};
    //printf("%d\n", arr[2]); warning: ISO C forbids subscripting ‘register’ array


    // Also adding register to a const variable prevents one from accidentally passing its pointer to another function that willfully ignore its constness
    register const int c = 3;


}