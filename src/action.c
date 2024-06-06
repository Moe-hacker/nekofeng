#include "include/nekofeng.h"
void blink_lefteye(int keep)
{
	struct ACTION *action = NULL;
	action = add_layer(action, 1, 0,
			   "  ██████ \n"
			   "██      ██\n"
			   "  ██████\n"
			   "  ██  ██\n"
			   "  ██████\n");
	action = add_layer(action, 1, 0,
			   "\n"
			   "  ██████ \n"
			   "██      ██\n"
			   "  ██  ██\n"
			   "  ██████\n");
	action = add_layer(action, 1, 0,
			   "\n\n"
			   "  ██████ \n"
			   "██      ██\n"
			   "  ██████\n");
	action = add_layer(action, 1, 0,
			   "\n\n\n"
			   "  ██████ \n"
			   "██████████\n");
	action = add_layer(action, 1, 0,
			   "\n\n"
			   "   ████\n"
			   "       ██\n"
			   "  █████\n");
	action = add_layer(action, 1, 0,
			   "\n"
			   "  ████\n"
			   "      ██\n"
			   "        ██\n"
			   "  ██████\n");
	play_action(action, 100000, keep);
	playback_action(action, 100000, keep);
	free_action(action);
}
void close_and_open_lefteye(int keep)
{
	struct ACTION *action = NULL;
	action = add_layer(action, 1, 0,
			   "  ██████ \n"
			   "██      ██\n"
			   "  ██████\n"
			   "  ██  ██\n"
			   "  ██████\n");
	action = add_layer(action, 1, 0,
			   "\n"
			   "  ██████ \n"
			   "██      ██\n"
			   "  ██  ██\n"
			   "  ██████\n");
	action = add_layer(action, 1, 0,
			   "\n\n"
			   "  ██████ \n"
			   "██      ██\n"
			   "  ██████\n");
	action = add_layer(action, 1, 0,
			   "\n\n\n"
			   "██████████\n"
			   "  ██████  \n");
	play_action(action, 100000, keep);
	playback_action(action, 100000, keep);
	free_action(action);
}
void close_and_open_righteye(int keep)
{
	struct ACTION *action = NULL;
	action = add_layer(action, 16, 0,
			   "  ██████ \n"
			   "██      ██\n"
			   "  ██████\n"
			   "  ██  ██\n"
			   "  ██████\n");
	action = add_layer(action, 16, 0,
			   "\n"
			   "  ██████ \n"
			   "██      ██\n"
			   "  ██  ██\n"
			   "  ██████\n");
	action = add_layer(action, 16, 0,
			   "\n\n"
			   "  ██████ \n"
			   "██      ██\n"
			   "  ██████\n");
	action = add_layer(action, 16, 0,
			   "\n\n\n"
			   "██████████\n"
			   "  ██████  \n");
	play_action(action, 100000, keep);
	playback_action(action, 100000, keep);
	free_action(action);
}
