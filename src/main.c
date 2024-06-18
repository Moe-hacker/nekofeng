#include "include/nekofeng.h"
int x;
int y;
// init() function for getting window size.
__attribute__((constructor)) void init()
{
	struct winsize size;
	ioctl(STDOUT_FILENO, TIOCGWINSZ, &size);
	x = size.ws_col / 2 - X_SIZE / 2;
	y = size.ws_row / 2 - Y_SIZE / 2;
}
/*
__attribute__((constructor)) void debug()
{
	struct winsize size;
	ioctl(STDOUT_FILENO, TIOCGWINSZ, &size);
	for (short i = 0; i < size.ws_col * size.ws_row; i++) {
		printf("#");
	}
}
*/
void test()
{
	close_and_open_lefteye(1);
	blink_lefteye(1);
}
void test2()
{
	close_and_open_righteye(2);
	close_and_open_righteye(2);
}
int main()
{
	struct LAYER layer;
	layer.layer = "\033[1;38;2;254;228;208m\n"
		      "          Keep moe.\n"
		      "          Keep cool.\n"
		      "         Keep hacking.\n"
		      "Keep on the side of technology.\n\n"
		      "      But talk is cheap,\n"
		      "       Show me the code.\n";
	layer.x_offset = 3;
	layer.y_offset = 0;
	printf("\033[?25l");
	typewrite_layer(&layer, 100000, true);
	sleep(2);
	clear_typewrite_layer(&layer, 50000);
	printf("\033[?25h");
	/*
		sleep(10);
		pid_t pid = fork();
		if (pid == 0) {
			test();
			exit(0);
		} else {
			waitpid(pid, NULL, WNOHANG);
		}
		pid = fork();
		if (pid == 0) {
			test2();
			exit(0);
		} else {
			waitpid(pid, NULL, WNOHANG);
		}
	*/
}
