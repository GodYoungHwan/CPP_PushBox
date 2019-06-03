#include "PushBoxGame.h"
#include "curses.h"


int main()
{
	PushBoxGame game;

	WINDOW* win1, * win2, * win3, * win4, * win5;

	char* arr = new char[11]; 
	for (int i = 0; i < 11; i++) {
		arr[i] = i + 65;
	}
	setlocale(LC_CTYPE, "ko_KR.utf-8");
	initscr();
	resize_term(35, 95);
	start_color();
	curs_set(0);
	noecho();
	init_pair(1, COLOR_WHITE, COLOR_BLACK);
	border('*', '*', '*', '*', '*', '*', '*', '*');
	refresh();
	//getch();

	win5 = newwin(27, 70, 4, 2);
	win1 = newwin(3, 15, 8, 75);
	win2 = newwin(3, 15, 12, 75);
	win3 = newwin(3, 15, 16, 75);
	win4 = newwin(3, 15, 20, 75);
	wbkgd(win1, COLOR_PAIR(1));
	wattron(win1, COLOR_PAIR(1));
	wbkgd(win2, COLOR_PAIR(1));
	wattron(win2, COLOR_PAIR(1));
	wbkgd(win3, COLOR_PAIR(1));
	wattron(win3, COLOR_PAIR(1));
	wbkgd(win4, COLOR_PAIR(1));
	wattron(win4, COLOR_PAIR(1));

	mvwprintw(win1, 1, 1, "level: ");
	mvwprintw(win1, 1, 8, " "); //�������� �ֱ�
	mvwprintw(win2, 1, 1, "move: ");
	mvwprintw(win2, 1, 8, " "); //�̵����� �ֱ�
	mvwprintw(win3, 1, 1, "goal: ");
	mvwprintw(win3, 1, 8, " "); //����Ƚ�� �ֱ�
	mvwprintw(win4, 1, 1, "time: ");
	mvwprintw(win4, 1, 8, " "); //�̵����� �ֱ�
	wborder(win1, '|', '|', '-', '-', '+', '+', '+', '+');
	wborder(win2, '|', '|', '-', '-', '+', '+', '+', '+');
	wborder(win3, '|', '|', '-', '-', '+', '+', '+', '+');
	wborder(win4, '|', '|', '-', '-', '+', '+', '+', '+');
	wborder(win5, '|', '|', '-', '-', '+', '+', '+', '+');

	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 20; j+=2) {
			switch (game.map[i][j/2])
			{
			case 1:mvwprintw(win5, i + 1, j + 1, "��");
				break;
			case 2:mvwprintw(win5, i + 1, j + 1, "��");
				break;
			case 0:mvwprintw(win5, i + 1, j + 1, " ");
				break;
			case 3:mvwprintw(win5, i + 1, j + 1, "��");
				break;
			case 4:mvwprintw(win5, i + 1, j + 1, " ");
				break;
			}
		}
	}

	wrefresh(win1);
	wrefresh(win2);
	wrefresh(win3);
	wrefresh(win4);
	wrefresh(win5);

	getch();

	delwin(win1);
	delwin(win2);
	delwin(win3);
	delwin(win4);
	delwin(win5);
	endwin();
	return 0;
}
