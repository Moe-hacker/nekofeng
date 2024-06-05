#include "include/nekofeng.h"
void blink_lefteye()
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
	play_action(action,300000);
    playback_action(action,100000);
    sleep(1);
	free_action(action);
}