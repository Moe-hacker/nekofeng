#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ioctl.h>
#include <sys/types.h>
#include <termios.h>
#include <time.h>
#include <unistd.h>
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
extern int x;
extern int y;
static void clear_layer(struct LAYER *layer);
static void print_layer(struct LAYER *layer);
void play_action(struct ACTION *action, int inr);
void playback_action(struct ACTION *action, int inr);
void free_action(struct ACTION *action);
struct ACTION *add_layer(struct ACTION *action, int x_offset, int y_offset, char *layer);
void blink_lefteye();