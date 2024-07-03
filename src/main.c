#include <stdio.h>
#include <unistd.h>

#include <ui/ui.h>

int main()
{
	ui_init();
	ui_start();
	ui_exit();

	return 0;
}
