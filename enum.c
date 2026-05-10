#include <stdio.h>

enum e {
 	X = 2,
 	Y = 2,
 	Z = 2,
};

/*
这也是为什么你的代码里 X = 2, Y = 2, Z = 2 三个名字不能在同一个作用域内重复定义——比如你不能再写另一个 enum 也叫 X，会冲突。
常见的 C 惯例是加前缀来避免命名冲突：
enum e {
    E_X = 2,
    E_Y = 2,
    E_Z = 2,
};
*/

int main(void){
	enum e A = X;
	enum e B = Y;
	printf("%d\n", A == B); // 1
}
