#include "my_apue.h"

int main(int argc,char *argv[]) {
	int fd, status;
	if(argc != 2) {
		printf("must has a file\n");
		exit(1);
	}
	// fd = open(argv[1], O_RDWR);
	fd = atoi(argv[1]);
	if(fd == -1) {
		perror("open");
		exit(1);
	}
	status = fcntl(fd, F_GETFL, 0);
	if(status == -1) {
		perror("fcntl");
	}
	switch (status) {
		case O_RDONLY:
			printf("O_RDONLY\n" );
			break;
		case O_RDWR:
			printf("O_RDWR\n" );
			break;
		case O_WRONLY:
			printf("O_WRONLY\n" );
			break;
	}
	if(status & O_APPEND) {
		printf("append\n");
	}
	if(status & O_NONBLOCK) {
		printf("no block\n");
	}
	if (status & O_SYNC) {
		printf("sync\n" );
	}
	return 0;
}
