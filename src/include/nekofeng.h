#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ioctl.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <termios.h>
#include <time.h>
#include <unistd.h>
#include <stdbool.h>
#define X_SIZE 36
#define Y_SIZE 2
struct LAYER {
	char *layer;
	int x_offset;
	int y_offset;
};
struct ACTION {
	struct LAYER *layer;
	struct ACTION *prior;
	struct ACTION *next;
};
struct MSG {
	char *msg;
	struct MSG *next;
};
extern int x;
extern int y;
static void clear_layer(struct LAYER *layer);
static void print_layer(struct LAYER *layer);
void play_action(struct ACTION *action, int inr, int keep);
void playback_action(struct ACTION *action, int inr, int keep);
void free_action(struct ACTION *action);
struct ACTION *add_layer(struct ACTION *action, int x_offset, int y_offset, char *layer);
void blink_lefteye(int keep);
void close_and_open_lefteye(int keep);
void close_and_open_righteye(int keep);
void typewrite_layer(struct LAYER *layer, int inr, bool blink);
void clear_typewrite_layer(struct LAYER *layer, int inr);
struct MSG *init_msg_buffer(int num);
void print_msg(struct MSG *msg, int x_offset, int y_offset);
void clear_msg(struct MSG *msg, int x_offset, int y_offset);
struct MSG *add_msg(struct MSG *buf, char *msg);
void free_msg(struct MSG *msg);
