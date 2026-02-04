// #include "add_h.h"
/*
Even, worse we might get into a crazy situation where header a.h includes header b.h, and b.h includes a.h! It’s an #include infinite cycle!
更糟的是，我们可能会陷入一个疯狂的情况，标题a.h包含标题b.h，而b.h包含a.h！这是一个 #include 无限的循环！
*/

#ifndef ADD_H   // If ADD_H isn't defined...
#include "add_h.h"
#define ADD_H   // Define it (with no particular value)
#endif

#include <stdio.h>

int main(void){
    printf("The summation is: %d\n", add(3,4));
}
