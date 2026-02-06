#include <stdio.h>


int main(void){
    char longstr[] = "abcdefghijklmnopqrst";
    char shortstr[] = "ABCD";
    printf(">12345678901234567890<\n>%s<\n>%s<\n\n\n", longstr, shortstr);
    

    
    printf("Using: %%10s\n");
    printf(">%10s<\n", longstr);
    printf(">%10s<\n", shortstr);
    printf("\n");

    printf("Using: %%-10s\n");
    printf(">%-10s<\n", longstr);
    printf(">%-10s<\n", shortstr);
    printf("\n");

    printf("Using: %%.10s\n");
    printf(">%.10s<\n", longstr);
    printf(">%.10s<\n", shortstr);
    printf("\n");

    printf("Using: %%15.10s\n");
    printf(">%15.10s<\n", longstr);
    printf(">%15.10s<\n", shortstr);
    printf("\n");

    printf("Using: %%-15.10s\n");
    printf(">%-15.10s<\n", longstr);
    printf(">%-15.10s<\n", shortstr);
    printf("\n");

    return 0;
} 
