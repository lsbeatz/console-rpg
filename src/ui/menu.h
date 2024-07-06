#ifndef MENU_H
#define MENU_H

enum main_menu_item {
	MAIN_NEW_GAME,
	MAIN_LOAD_GAME,
	MAIN_CONFIGURE,
	MAIN_EXIT,

	NR_MAIN_MENU_ITEMS,
};

struct main_menu_cfg {
	char *name;
	int (*func)(void);
};

void menu_init(void);
int menu_start(void);

#endif /* MENU_H */
