#include "my_apue.h"

int main(int argc, char const *argv[]) {
	if(argc != 2) {
		printf("arg must has a file\n");
	}
	int mode, fd;
	if((mode = access(argv[1] ,R_OK)) == -1) {
		perror("access");
		exit(1);
	}
	if(mode == F_OK) {
		printf("can read\n");
	}
	fd = open(argv[1], O_RDONLY);
	if(fd == -1) {
		perror("open");
	exit(1);
	}
	if(fd > 0) {
		printf("open success\n");
	}

	close(fd);

	return 0;
}
