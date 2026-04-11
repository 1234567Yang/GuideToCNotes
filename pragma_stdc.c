#include <stdio.h>

int main(void){
    // FP_CONTRACT: Allow floating point expressions to be contracted into a single operation to avoid rounding errors that might occur from multiple operations.
    
    double a = 1.0e20;
    double b = 1.0e20;
    double c = -1.0e40;
    // "contract"（收缩）指的是把多步浮点运算合并成一条硬件指令。最典型的例子是 FMA（fused multiply-add）：
    #pragma STDC FP_CONTRACT ON
    
    double result = a * b + c;

    #pragma STDC FP_CONTRACT OFF

    double result_off = a * b + c;


    /*
    这是最主要的原因。GCC 对这个标准 pragma 的支持很差，基本会直接忽略它。
    */
    
    printf("When open, the result is: %f; When close, the result is: %f; \n", result, result_off);
    // 不开 FP_CONTRACT 时，编译器先算 a * b，舍入一次，再加 c，再舍入一次——两次舍入。开了之后，编译器可以用一条 FMA 指令完成，只舍入一次，精度反而更高。但结果会和严格按两步算的不一样，所以标准让你自己选。

    // FENV_ACCESS: Set to ON if you plan to access the floating point status flags. If OFF, the compiler might perform optimizations that cause the values in the flags to be inconsistent or invalid.
    // CX_LIMITED_RANGE: Set to ON to allow the compiler to skip overflow checks when performing complex arithmetic. Defaults to OFF.



}
