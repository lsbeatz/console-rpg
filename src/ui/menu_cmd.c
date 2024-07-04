#include <ncurses.h>

int main_menu_new_game(void)
{
	return 0;
}

int main_menu_load_game(void)
{
	return 0;
}

int main_menu_configure(void)
{
	return 0;
}

int main_menu_exit(void)
{
	int ch;

	attrset(A_BOLD);
	printw("Press any key to exit\n");
	refresh();

	ch = getch();

	return ch;
}


