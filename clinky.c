#include <stdio.h>
#include <ncurses.h>
#include <stdlib.h>


#define WIDTH 30
#define HEIGHT 10

int startx = 0;
int starty = 0;
char *labels[] = {  /* set up an array for things to track */
	"mem",
	"cpu",
    };


int main() {
    initscr();
    noecho();

    mvprintw(0, 0,"%s", labels[0]);
    mvprintw(0, 5,"%s", labels[1]);
    refresh();
    getch();
    endwin();
    noecho();

    return 0;
}
