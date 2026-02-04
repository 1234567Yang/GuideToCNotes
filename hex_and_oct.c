#include <stdio.h>

int main(void){
    int a = 0x1A2B;   // Hexadecimal
    int b = 0x1a2b;   // Case doesn't matter for hex digits

    printf("%x\n", a);  // Print a hex number, "1a2b"

    int c = 012;

    printf("%o %d\n", c, c);  // Print an octal number, "12 10"


    // An unofficial extension in many C compilers allows you to represent a binary number with a 0b prefix:

    int x = 0b101010;    // Binary 101010
    printf("%d\n", x);   // Prints 42 decimal




    // C11 §6.4.4.1¶5 The type of an integer constant is the first of the first of the corresponding list in which its value can be represented
    // What that’s saying is that, for example, if you specify a number like 123456789U, first C will see if it can be unsigned int. If it doesn’t fit there, it’ll try unsigned long int. And then unsigned long long int. It’ll use the smallest type that can hold the number.


    // unsuffiexed floating point numbers are type double
    // You can force it to be of type float by appending an f (or F—it’s case-insensitive). You can force it to be of type long double by appending l (or L).

    printf("%d\n", 1.2345e10 == 1.2345e+10);


    double x2 = 0xa.1p3;

    printf("%a\n", x2);  // 0x1.42p+6 %a -> 十六进制浮点数
    printf("%f\n", x2);  // 80.500000
    // 为什么底数不同？关键在于：十六进制本身就是二进制的"压缩表示"。

}


