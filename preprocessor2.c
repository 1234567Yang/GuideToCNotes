#include <stdio.h>
#include <math.h>

#define SQUARE(x) x * x
#define SQUARECORRECT(x) ((x) * (x))

#define QUADP(a, b, c) ((-(b) + sqrt((b) * (b) - 4 * (a) * (c))) / (2 * (a)))
#define QUADM(a, b, c) ((-(b) - sqrt((b) * (b) - 4 * (a) * (c))) / (2 * (a)))
#define QUAD(a, b, c) QUADP(a, b, c), QUADM(a, b, c)

#define X(a, b, ...) (10*(a) + 20*(b)), __VA_ARGS__


int main(char *args[], int argp){
    printf("%d\n", SQUARE(4));
    printf("%d\n", SQUARE(3 + 2));
	// 展开成：3 + 2 * 3 + 2
	// 计算为：3 + 6 + 2 = 11
	// 而不是预期的 25
    printf("%d\n", SQUARECORRECT(3 + 2));


	printf("2x^2+10x+5 result is %f or %f\n", QUAD(2,10,5));
	
	
	printf("%d %f %s %d\n", X(5, 4, 3.14, "Hi!", 12));
	
	
	return 0;
}
