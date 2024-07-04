#include <assert.h>
#include <ncurses.h>

#include "menu.h"
#include "menu_cmd.h"

static int select_main_menu(void);
static void show_main_menu(void);

static enum main_menu_item cur_main_menu_item;
static struct main_menu_cfg main_cfgs[NR_MAIN_MENU_ITEMS] = {
	{"1. New Game"	, main_menu_new_game	},
	{"2. Load Game"	, main_menu_load_game	},
	{"3. Configure"	, main_menu_configure	},
	{"4. Exit"		, main_menu_exit		},
};

static int select_main_menu(void)
{
	int ch;

	ch = getch();
	switch(ch) {
	case KEY_UP:
		if (cur_main_menu_item > MAIN_NEW_GAME) {
			cur_main_menu_item--;
		}
		break;

	case KEY_DOWN:
	case KEY_STAB:
		if (cur_main_menu_item < MAIN_EXIT) {
			cur_main_menu_item++;
		}
		break;

	default:
		break;
	}

	return (ch == '\n');
}

static void show_main_menu(void)
{
	clear();
	for (int i = 0; i < NR_MAIN_MENU_ITEMS; i++) {
		if (i == cur_main_menu_item) {
			attrset(A_UNDERLINE);
			printw("%s\n", main_cfgs[i].name);
			attrset(A_NORMAL);
		} else {
			printw("%s\n", main_cfgs[i].name);
		}
	}
	refresh();
}

void menu_init(void)
{
	cur_main_menu_item = MAIN_NEW_GAME;
}

int do_menu(void)
{
	int is_selected = 0;

	while (!is_selected) {
		show_main_menu();
		is_selected = select_main_menu();
	}

	printw("menu %d selected\n", 1 + cur_main_menu_item);
	refresh();

	return main_cfgs[cur_main_menu_item].func();
}
