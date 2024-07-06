#include <ncurses.h>
#include <ui/ui.h>

#include "menu.h"

void ui_init(void)
{
	initscr();
	raw(); // Alt: cbreak()
	keypad(stdscr, TRUE);
	noecho();

	clear();

	printw("Press any key to start!\n");
	refresh();
	getch();

	menu_init();
}

int ui_start()
{
	int rc;

	rc = menu_start();

	return rc;
}

void ui_exit(void)
{
	clear();
	noraw();
	endwin();
}
