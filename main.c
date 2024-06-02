#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ioctl.h>
#include <sys/types.h>
#include <termios.h>
#include <time.h>
#include <unistd.h>
#define X_SIZE 12
#define Y_SIZE 2
struct LAYER {
  char *layer;
  int x_offset;
  int y_offset;
};
struct ACTION {
  struct LAYER *layer;
  struct ACTION *next;
};
static int x;
static int y;
// init() function for getting window size.
__attribute__((constructor)) void init() {
  struct winsize size;
  ioctl(STDOUT_FILENO, TIOCGWINSZ, &size);
  x = size.ws_col / 2 - X_SIZE / 2;
  y = size.ws_row / 2 - Y_SIZE / 2;
}
static void clear_layer(struct LAYER *layer) {
  int y_offset = 0;
  int x_offset = 0;
  printf("\033[%dH", y + layer->y_offset);
  printf("\033[%dG", x + layer->x_offset);
  for (size_t i = 0; i < strlen(layer->layer); i++) {
    // The next line.
    if (layer->layer[i] == '\n') {
      y_offset++;
      x_offset = 0;
      printf("\033[%dH", y + layer->y_offset + y_offset);
      printf("\033[%dG", x + layer->x_offset);
      continue;
    }
    // Unicode.
    if (layer->layer[i] > 127) {
      i += 3;
    }
    // Color.
    if (layer->layer[i] == '\033') {
      for (int j = i; j < strlen(layer->layer); j++) {
        if (layer->layer[j] == 'm') {
          i = j;
          break;
        }
      }
    }
    // Skip space.
    if (layer->layer[i] != ' ') {
      printf("\033[%dG", x + layer->x_offset + x_offset);
      printf("%c", ' ');
    }
    x_offset++;
  }
  fflush(stdout);
}
static void print_layer(struct LAYER *layer) {
  int y_offset = 0;
  printf("\033[%dH", y + layer->y_offset);
  printf("\033[%dG", x + layer->x_offset);
  for (size_t i = 0; i < strlen(layer->layer); i++) {
    // The next line.
    if (layer->layer[i] == '\n') {
      y_offset++;
      printf("\033[%dH", y + layer->y_offset + y_offset);
      printf("\033[%dG", x + layer->x_offset);
      continue;
    }
    // Skip space.
    if (layer->layer[i] != ' ') {
      printf("%c", layer->layer[i]);
    } else {
      printf("\033[1C");
    }
  }
  fflush(stdout);
}
int main() {
  struct LAYER layer;
  layer.x_offset = 0;
  layer.y_offset = 0;
  layer.layer = "\033[33mhshshshhsh█iyf8fyftf\n    hdhdhshshsh";
  print_layer(&layer);
  sleep(1);
  clear_layer(&layer);
  sleep(1);
  print_layer(&layer);
  sleep(1);
  struct LAYER layer1;
  layer1.x_offset = 0;
  layer1.y_offset = 0;
  layer1.layer = "\033[33mhshshshhshdjhdhdhiyf8fyftf\n    hhdhehehhdhdhhddhhsgsggshsd>";
  print_layer(&layer1);
  sleep(1);
  clear_layer(&layer1);
  struct LAYER layer2;
  layer2.x_offset = 0;
  layer2.y_offset = 0;
  layer2.layer = "\033[33mhshshshhsh█iyf8fyftf\n    hd>";
  print_layer(&layer2);
  sleep(1);
  clear_layer(&layer2);
}
