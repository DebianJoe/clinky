#include <stdio.h>
#include <stdlib.h>
#include <sys/sysinfo.h>
#include <unistd.h>
#include <math.h>

/* set conversion constants */
const double megabyte = 1024 * 1024;

int main() {
    struct sysinfo si;
    sysinfo (&si);

    unsigned long totalmem = si.totalram *(unsigned long long)si.mem_unit / megabyte;
    unsigned long usedmem = ((si.totalram *(unsigned long long)si.mem_unit) -
			     (si.freeram *(unsigned long long)si.mem_unit)) / megabyte;
    unsigned long buffermem = (si.bufferram *(unsigned long long)si.mem_unit) / megabyte;
    /* raw readings */
    printf("Total Ram: %lluk\tFree: %lluk\n",
	   si.totalram *(unsigned long long)si.mem_unit / 1024,
	   si.freeram *(unsigned long long)si.mem_unit / 1024);
    printf("Total: \033[1;31m%luM\033[1;m in human form\n", totalmem);
    printf("Used:  %luM in human form\n", usedmem);
    printf("Buffer:%luM in human form\n", buffermem);
    long size = sysconf(_SC_LEVEL1_ICACHE_SIZE) / pow(2, 10);
    long assoc = sysconf(_SC_LEVEL1_ICACHE_ASSOC);
    long line = sysconf(_SC_LEVEL1_ICACHE_LINESIZE);
    printf("lvl 1 icache size = %ldK, assoc = %ld, line size = %ld\n", size, assoc, line);

    size = sysconf(_SC_LEVEL1_DCACHE_SIZE) / pow(2, 10);
    assoc = sysconf(_SC_LEVEL1_DCACHE_ASSOC);
    line = sysconf(_SC_LEVEL1_DCACHE_LINESIZE);
    printf("lvl 1 dcache size = %ldK, assoc = %ld, line size = %ld\n", size, assoc, line);

    size = sysconf(_SC_LEVEL2_CACHE_SIZE) / pow(2, 10);
    assoc = sysconf(_SC_LEVEL2_CACHE_ASSOC);
    line = sysconf(_SC_LEVEL2_CACHE_LINESIZE);
    printf("lvl 2 cache size = %ldK, assoc = %ld, line size = %ld\n", size, assoc, line);


    return 0;
}
