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
#define SLEEP_TIME 200000
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
    if (layer->layer[i] > 0x7f || layer->layer[i] < 0) {
      i += 2;
    }
    // Color.
    if (layer->layer[i] == '\033') {
      for (int j = i; j < strlen(layer->layer); j++) {
        if (layer->layer[j] == 'm') {
          i = j;
          break;
        }
      }
      continue;
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
void load_action(struct ACTION *action) {
  struct ACTION **p = &action;
  while ((*p) != NULL) {
    print_layer((*p)->layer);
    usleep(SLEEP_TIME);
    clear_layer((*p)->layer);
    p = &((*p)->next);
  }
}
void free_action(struct ACTION *action) {
  struct ACTION *p = action;
  while (p != NULL) {
    struct ACTION *t = p;
    p = p->next;
    free(t->layer->layer);
    free(t->layer);
    free(t);
  }
}
struct ACTION *add_layer(struct ACTION *action, int x_offset, int y_offset,
                         char *layer) {
  struct ACTION **p = &action;
  while (*p != NULL) {
    p = &((*p)->next);
  }
  (*p) = malloc(sizeof(struct ACTION));
  (*p)->layer = malloc(sizeof(struct LAYER));
  (*p)->layer->x_offset = x_offset;
  (*p)->layer->y_offset = y_offset;
  (*p)->layer->layer = strdup(layer);
  (*p)->next = NULL;
  return action;
}
void blink_lefteye() {
  struct ACTION *action = NULL;
  action = add_layer(action, 5, 0,
                     "  ██████ \n"
                     "██      ██\n"
                     "  ██████\n"
                     "  ██  ██\n"
                     "  ██████\n");
  action = add_layer(action, 5, 0,
                     "\n"
                     "  ██████ \n"
                     "██      ██\n"
                     "  ██  ██\n"
                     "  ██████\n");
  action = add_layer(action, 5, 0,
                     "\n\n"
                     "  ██████ \n"
                     "██      ██\n"
                     "  ██████\n");
  action = add_layer(action, 5, 0,
                     "\n\n\n"
                     "  ██████ \n"
                     "██████████\n");
  action = add_layer(action, 5, 0,
                     "\n\n"
                     "     ██\n"
                     "       ██\n"
                     "  █████\n");
  action = add_layer(action, 5, 0,
                     "\n"
                     "  ████\n"
                     "      ██\n"
                     "        ██\n"
                     "  ██████\n");
  load_action(action);
  free_action(action);
}

int main() { blink_lefteye(); }
