all:
	cc -fsanitize=address -ggdb src/main.c src/layer.c src/action.c -o nekofeng
format:
	clang-format -i src/main.c src/include/nekofeng.h
