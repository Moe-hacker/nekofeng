#include "include/nekofeng.h"
void blink_lefteye(int keep)
{
	struct ACTION *action = NULL;
	action = add_action(action, 1, 0,
			    "  ██████ \n"
			    "██      ██\n"
			    "  ██████\n"
			    "  ██  ██\n"
			    "  ██████\n");
	action = add_action(action, 1, 0,
			    "\n"
			    "  ██████ \n"
			    "██      ██\n"
			    "  ██  ██\n"
			    "  ██████\n");
	action = add_action(action, 1, 0,
			    "\n\n"
			    "  ██████ \n"
			    "██      ██\n"
			    "  ██████\n");
	action = add_action(action, 1, 0,
			    "\n\n\n"
			    "  ██████ \n"
			    "██████████\n");
	action = add_action(action, 1, 0,
			    "\n\n"
			    "   ████\n"
			    "       ██\n"
			    "  █████\n");
	action = add_action(action, 1, 0,
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
	action = add_action(action, 1, 0,
			    "  ██████ \n"
			    "██      ██\n"
			    "  ██████\n"
			    "  ██  ██\n"
			    "  ██████\n");
	action = add_action(action, 1, 0,
			    "\n"
			    "  ██████ \n"
			    "██      ██\n"
			    "  ██  ██\n"
			    "  ██████\n");
	action = add_action(action, 1, 0,
			    "\n\n"
			    "  ██████ \n"
			    "██      ██\n"
			    "  ██████\n");
	action = add_action(action, 1, 0,
			    "\n\n\n"
			    "██████████\n"
			    "  ██████  \n");
	action = add_action(action, 1, 0,
			    "\n\n\n"
			    "\n"
			    "  ██████  \n");
	play_action(action, 100000, keep);
	playback_action(action, 100000, keep);
	free_action(action);
}
void close_and_open_righteye(int keep)
{
	struct ACTION *action = NULL;
	action = add_action(action, 16, 0,
			    "  ██████ \n"
			    "██      ██\n"
			    "  \033[31m██  ██\n"
			    "    ██  \n"
			    "  ██  ██\n");
	action = add_action(action, 16, 0,
			    "\n"
			    "  ██████ \n"
			    "██\033[31m██  ██\033[0m██\n"
			    "    \033[31m██\n"
			    "  ██  ██\n");
	action = add_action(action, 16, 0,
			    "\n\n"
			    "  ██████ \n"
			    "██  \033[31m██\033[0m  ██\n"
			    "  \033[31m██  ██\n");
	action = add_action(action, 16, 0,
			    "\n\n\n"
			    "  ██████  \n"
			    "██\033[31m██  ██\033[0m██ \n");
	action = add_action(action, 16, 0,
			    "\n\n\n"
			    "\n"
			    "  ██████  \n");
	play_action(action, 100000, keep);
	playback_action(action, 100000, keep);
	free_action(action);
}
