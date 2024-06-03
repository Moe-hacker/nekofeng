all:
	cc -fsanitize=address -ggdb main.c
format:
	clang-format -i main.c