test_var := "test\n\n\n"


test_method:
	printf $(test_var)


# 当规则有多个目标时，会为每个目标执行命令。$@ 是一个自动变量，包含目标名称。
all:f1.o f2.o
f1.o f2.o:
	echo $@
	# Equivalent to:
	# # f1.o:
	# #	 echo f1.o
	# # f2.o:
	# #	 echo f2.o

hi:
	echo "hi"

hello:hi
	echo "hello"

hey:
	echo "hey"
	gcc -o test test.c

run:hey
	chmod 744 test
	printf "\n\n\n\n"
	./test


clean:
	rm -f test





# thing_wrong := *.o — 变量赋值时 * 不会被展开。所以 thing_wrong 的值就是字面字符串 "*.o"，不是文件列表。后面 one: $(thing_wrong) 相当于 one: *.o 这个字面字符串，Make 会去找一个真的叫 *.o 的文件（名字里带星号的文件），找不到就报错。
# two: *.o — 写在 prerequisite 里，* 会展开，但有个陷阱：如果当前目录没有任何 .o 文件，它不会展开成空，而是保持字面值 *.o。这跟 bash 的默认行为一样（nullglob 没开的时候）。所以你以为它是"没有依赖"，实际上它依赖一个不存在的文件 *.o。
# thing_right := $(wildcard *.o) — 用 wildcard 函数就安全了。没有匹配文件时它会返回空字符串，而不是保留字面值。所以 three: $(thing_right) 在没有 .o 文件时等价于 three:，就是没有依赖，不会出错。
# four: $(wildcard *.o) — 跟 three 效果一样，只是直接内联写而不是存到变量里。


# Print out file information about every .c file
print: $(wildcard *.c)
	ls -la  $?






