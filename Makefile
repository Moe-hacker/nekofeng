all:
	cc -fsanitize=address -ggdb src/main.c src/layer.c src/action.c src/tty.c -o nekofeng
format:
	clang-format -i src/*.c src/include/*.h
