#include <stdio.h>
#include <stdlib.h>

int main(void){
    char chr[50];
    FILE *f = fopen("test.txt", "r");
    int a = 100, b = 100, c = 100;
    int res = fscanf(f, "%d %*d %d %49s %d", &a, &b, chr, &c);
    // 多出来的会自动截断，不影响下一个读取
    // 但是如果被截断的话，虽然会保存到变量，但是 res 里面并不会显示为成功
    printf("res: %d \n%d %d %s %d\n\n", res, a, b, chr, c);

    fclose(f);
}
