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
	int ret = 0;
	struct MSG **p = &msg;
	while ((*p) != NULL) {
		if ((*p)->msg == NULL) {
			return ret;
		}
		ret++;
		p = &((*p)->next);
	}
	return ret;
}
static int get_buf_count(struct MSG *msg)
{
	int ret = 0;
	struct MSG **p = &msg;
	while ((*p) != NULL) {
		ret++;
		p = &((*p)->next);
	}
	return ret;
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
}
static char *get_last_msg(struct MSG *msg)
{
	char *ret;
	struct MSG **p = &msg;
	while ((*p) != NULL) {
		if ((*p)->msg == NULL) {
			return ret;
		}
		ret = (*p)->msg;
		p = &((*p)->next);
	}
	return ret;
}
static struct ACTION *msg_to_action(struct MSG *msg, int x_offset, int y_offset)
{
	char *buf = NULL;
	char *tmp = NULL;
	size_t size = 0;
	int msgs = get_msg_count(msg);
	int bufs = get_buf_count(msg);
	size = bufs + 1;
	buf = malloc(size);
	buf[0] = '\0';
	for (int i = 0; i < bufs - msgs; i++) {
		strcat(buf, "\n");
	}
	struct MSG **p = &msg;
	for (int i = 0; i < msgs - 1; i++) {
		if ((*p)->msg == NULL) {
			break;
		}
		size += (strlen((*p)->msg) + 4);
		if (buf != NULL) {
			tmp = strdup(buf);
			free(buf);
			buf = malloc(size);
			sprintf(buf, "%s%s\n", tmp, (*p)->msg);
			free(tmp);
			tmp = NULL;
		} else {
			buf = malloc(size);
			sprintf(buf, "%s\n", (*p)->msg);
		}
		p = &((*p)->next);
	}
	struct ACTION *ret = add_action(NULL, x_offset, y_offset, buf);
	char *last_msg = get_last_msg(msg);
	size += strlen(last_msg) + 4;
	tmp = strdup(buf);
	free(buf);
	buf = malloc(size);
	sprintf(buf, "%s\n", tmp);
	free(tmp);
	tmp = NULL;
	for (size_t i = 0; i < strlen(last_msg); i++) {
		tmp = strdup(buf);
		sprintf(buf, "%s%c", tmp, last_msg[i]);
		free(tmp);
		ret = add_action(ret, x_offset, y_offset, buf);
	}
	free(buf);
	return ret;
}
void print_msg(struct MSG *msg, int x_offset, int y_offset)
{
	struct ACTION *action = msg_to_action(msg, x_offset, y_offset);
	play_action(action, 10000, 1);
	free_action(action);
}
