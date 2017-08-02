#include "my_apue.h"

int main(int argc, char const *argv[]) {
	int fd;
	fd = open("tempfile", O_RDWR | O_CREAT, 0755);
	if(fd == -1) {
		perror("open");
		exit(1);
	}
	printf("create tempfile\n");
	sleep(10);
	printf("start unlink\n");
	if(unlink("tempfile")) {
		perror("unlink");
	}
	printf("has unlink\n");
	printf("start sleep\n");
	sleep(15);
	printf("done\n");

	return 0;
}
