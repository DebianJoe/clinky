#include <stdio.h>
#include <stdlib.h>
#include <sys/sysinfo.h>
#include <sys/utsname.h>
#include <unistd.h>
#include <math.h>

#define TO_MB(m) ((m * (unsigned long long)si.mem_unit) / MEGABYTE)

/* set conversion constants */
const double MEGABYTE = 1024 * 1024;

int main() {
    struct sysinfo si;
    struct utsname ut;
    sysinfo(&si);
    uname(&ut);

    unsigned long totalmem = TO_MB(si.totalram);
    unsigned long usedmem = TO_MB(si.totalram - si.freeram);
    unsigned long buffermem = TO_MB(si.bufferram);
    unsigned long freemem = TO_MB(si.freeram);

    long cpus = sysconf(_SC_NPROCESSORS_ONLN);
    long csize = sysconf(_SC_LEVEL1_ICACHE_SIZE) / pow(2, 10);
    long cassoc = sysconf(_SC_LEVEL1_ICACHE_ASSOC);
    long cline = sysconf(_SC_LEVEL1_ICACHE_LINESIZE);

    csize = sysconf(_SC_LEVEL1_DCACHE_SIZE) / pow(2, 10);
    cassoc = sysconf(_SC_LEVEL1_DCACHE_ASSOC);
    cline = sysconf(_SC_LEVEL1_DCACHE_LINESIZE);
    csize = sysconf(_SC_LEVEL2_CACHE_SIZE) / pow(2, 10);
    cassoc = sysconf(_SC_LEVEL2_CACHE_ASSOC);
    cline = sysconf(_SC_LEVEL2_CACHE_LINESIZE);

    /* raw readings */
    printf("\033[1;33m+++ \033[1;32mClinky \033[1;33m+++\033[1;m\n\n");
    printf("uname:\t\t\033[1;31m%s %s %s\033[1;m\n", ut.sysname, ut.release, ut.version);
    printf("Hostname:\t\033[1;31m%s\033[1;m\n", ut.nodename);
    printf("Total:\t\t\033[1;31m%lu M\033[1;m\n", totalmem);
    printf("Used:\t\t\033[1;31m%lu M\033[1;m (cache not subtracted)\n", usedmem);
    printf("Free:\t\t\033[1;31m%lu M\033[1;m\n", freemem);
    printf("Buffer:\t\t\033[1;31m%lu M\033[1;m\n", buffermem);
    printf("Uptime:\t\t\033[1;31m%ld\033[1;m in seconds.\n", si.uptime);
    printf("Load:\t\t\033[1;31m%.2f\033[1;m\n", si.loads[0] / 65536.0);
    printf("Processes:\t\033[1;31m%d\033[1;m\n", si.procs);
    printf("Page size:\t\033[1;31m%ld\033[1;m bytes\n", sysconf(_SC_PAGESIZE));
    printf("CPUs:\t\t\033[1;31m%ld\033[1;m\n\n", cpus);
    printf("lvl 1 icache size = %ldK, \n\tassoc = %ld, \n\tline size = %ld\n",
	   csize, cassoc, cline);
    printf("lvl 1 dcache size = %ldK, \n\tassoc = %ld, \n\tline size = %ld\n",
	   csize, cassoc, cline);
    printf("lvl 2 cache size = %ldK, \n\tassoc = %ld, \n\tline size = %ld\n",
	   csize, cassoc, cline);
    return 0;
}
