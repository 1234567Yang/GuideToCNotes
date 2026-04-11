#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void vulnerable(char *input) {
    char buf[16];
    strcpy(buf, input);  // 没有边界检查，可能溢出
    printf("buf: %s\n", buf);
}

int main(int argc, char *argv[]) {
    if (argc < 2) return 1;
    vulnerable(argv[1]);
    return 0;
}
// gcc -fstack-protector stack_canary_compiler.c -o stack_canary_compiler
// 如果是 [8] 但是 01234567的话，\0 确实溢出了，但它落在了**编译器的对齐填充（padding）**里，没碰到 canary。
// 已经改用 [16] 测试过，输入012345678
