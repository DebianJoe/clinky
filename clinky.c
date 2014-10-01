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
    /* initscr(); */
    /* noecho(); */
    struct sysinfo si;
    sysinfo (&si);

    unsigned long totalmem = si.totalram *(unsigned long long)si.mem_unit / megabyte;
    unsigned long usedmem = ((si.totalram *(unsigned long long)si.mem_unit) -
			     (si.freeram *(unsigned long long)si.mem_unit)) / megabyte;
    unsigned long buffermem = (si.bufferram *(unsigned long long)si.mem_unit) / megabyte;


    /* screen formatting, delayed until I get everything else working */
    /* mvprintw(0, 0,"%s", labels[0]); */
    /* mvprintw(1, 0,"%5.1f", */
    /* 	     ((si.totalram - si.freeram) - si.bufferram) / megabyte); */
    /* mvprintw(0, 5,"%s", labels[1]); */
    /* mvprintw(1, 5,"%k", */
    /* 	     (si.totalram *(unsigned long long)si.mem_unit / 1024)); */
    /* refresh(); */
    /* getch(); */
    /* endwin(); */
    /* noecho(); */

    /* raw readings */
    printf("Total Ram: %lluk\tFree: %lluk\n",
	   si.totalram *(unsigned long long)si.mem_unit / 1024,
	   si.freeram *(unsigned long long)si.mem_unit / 1024);
    printf("Total: %lu in human form\n", totalmem);
    printf("Used:  %lu in human form\n", usedmem);
    printf("Buffer:%lu in human form\n", buffermem);

    return 0;
}
