#include "my_apue.h"
#include <dirent.h>
#include <limits.h>

typedef int Myfunc(const char *,const struct stat *, int);

static Myfunc myfunc;
static int myftw(char *,Myfunc *);
static int dopath(Myfunc *);
static long nreg, ndir, nblk, nchr, nfifo, nslink, nsock, ntot;

int main(int argc, char const *argv[]) {
	int ret;
	if(argc != 2) {
		printf("must has a direction\n");
		exit(1);
	}
	ret = myftw(argv[1], myfunc);
	return 0;
}

#define FTW_F 1
#define FTW_D 2
#define FTW_DNR 3
#define FTW_NS 4

static char *fullpath;
static size_t pathlen;

static int myftw(char *pathname, Myfunc *func) {
	fullpath = path_alloc(&pathlen);
	if(pathlen <= strlen(pathname)) {
		pathlen = strlen(pathname);
		if((fullpath = realloc(fullpath, pathlen)) == NULL) {
			perror("realloc");
			exit(1);
		}
	}
	strcpy(fullpath, pathname);
	return (dopath(func));
}
static int dopath(Myfunc *func) {
	struct stat statubuf;
	struct dirent *dirp;
	DIR *dp;
	int ret,n;
	if(lstat(fullpath, &statbuf) < 0) {
		return (func(fullpath, &statbuf, FTW_NS));
	}
	if(S_ISDIR(statbuf.st_mode) == 0) {
		return (func(full, &statbuf, FTW_F));
	}
	
}
