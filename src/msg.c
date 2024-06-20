#include "include/nekofeng.h"
struct MSG *init_msg_buffer(int num)
{
	struct MSG *ret;
	struct MSG **p = &ret;
	for (int i = 0; i < num; i++) {
		(*p) = malloc(sizeof(struct MSG));
		(*p)->msg = NULL;
		(*p)->next = NULL;
		p = &((*p)->next);
	}
	return ret;
}
static int get_msg_count(struct MSG *msg)
{
	struct MSG **p = &msg;
	for (int i = 1;; i++) {
		if ((*p) == NULL) {
			return i;
		}
		p = &(*p)->next;
	}
}
void free_msg(struct MSG *msg)
{
	struct MSG *p = msg;
	while (p != NULL) {
		struct MSG *t = p;
		p = p->next;
		free(t);
	}
}
struct MSG *add_msg(struct MSG *buf, char *msg)
{
	struct MSG **p = &buf;
	while ((*p) != NULL) {
		if ((*p)->msg == NULL) {
			(*p)->msg = msg;
			return buf;
		}
		p = &((*p)->next);
	}
	struct MSG *ret = buf->next;
	free(buf);
	p = &ret;
	while (true) {
		if ((*p) == NULL) {
			(*p) = malloc(sizeof(struct MSG));
			(*p)->msg = msg;
			(*p)->next = NULL;
			break;
		}
		p = &(*p)->next;
	}
	return ret;
	return buf;
}

void print_msg(struct MSG *msg, int x_offset, int y_offset)
{
	struct MSG **p = &msg;
	while ((*p) != NULL) {
		if ((*p)->msg == NULL) {
			return;
		}
		printf("%s\n", (*p)->msg);
		fflush(stdout);
		p = &((*p)->next);
	}
}
void print_msg(struct MSG *msg, int x_offset, int y_offset)
{
}
void clear_msg(struct MSG *msg, int x_offset, int y_offset)
{
}
