#include <stdio.h>
#include <ncurses.h>
#include <stdlib.h>
#include <sys/sysinfo.h>

#define WIDTH 30
#define HEIGHT 10

/* set conversion constants */
const long minute = 60;
const double megabyte = 1024 * 1024;
int startx = 0;
int starty = 0;
char *labels[] = {  /* set up an array for things to track */
	"mem",
	"cpu",
    };


int main() {
    initscr();
    noecho();
    struct sysinfo si;
    sysinfo (&si);

    mvprintw(0, 0,"%s", labels[0]);
    mvprintw(1, 0,"%5.1f", (si.totalram - si.freeram) / megabyte);
    mvprintw(0, 5,"%s", labels[1]);
    refresh();
    getch();
    endwin();
    noecho();

    return 0;
}
