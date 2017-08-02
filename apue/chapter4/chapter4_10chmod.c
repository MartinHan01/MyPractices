#include "my_apue.h"

int main(int argc, char const *argv[]) {
	struct stat statbuf;
	if(stat("bar", &statbuf) == -1) {
		perror("stat");
		exit(1);
	}
	if(chmod("bar", (statbuf.st_mode | S_IWGRP)) == -1) {
		perror("chmod");
		exit(1);
	}
	stat("foo", &statbuf);
	chmod("foo", (statbuf.st_mode & ~(S_IXOTH | S_IXGRP | S_IXUSR)));

	return 0;
}
