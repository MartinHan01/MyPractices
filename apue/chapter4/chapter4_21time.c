#include "my_apue.h"

int main(int argc, char const *argv[]) {
	int i,fd;
	struct stat statbuf;
	struct timespec timebuf[2];
	if(argc == 1) {
		printf("must has a chmod file\n");
		exit(1);
	}
	for(i = 1; i < argc ; i++) {
		if(stat(argv[i], &statbuf) == -1) {
			perror("stat");
			continue;
		}
		if((fd = open(argv[i], O_RDWR)) == -1) {
			perror("open");
			continue;
		}
		if(write(fd, "123",3) == -1) {
			perror("write\n");
			continue;
		}
		timebuf[0] = statbuf.st_atim;
		timebuf[1] = statbuf.st_mtim;
		if(futimens(fd, timebuf) == -1) {
			perror("futimes");
			continue;
		}
		close(fd);
	}
	return 0;
}
