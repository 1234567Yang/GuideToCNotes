#include <stdio.h>

#define PRINT_VAR(x) printf("%s = %d\n", #x, x)

typedef union test_union{
    struct {
        int x, y;
    } a;
    struct {
        int z, w;
    } b;
} test_union;


int main(void){
    test_union u;
    u.a.x = 1;
    u.a.y = 2;
    u.b.z = 3;
    u.b.w = 4;
    
    PRINT_VAR(u.a.x);
    PRINT_VAR(u.a.y);
    PRINT_VAR(u.b.z);
    PRINT_VAR(u.b.w);
}
