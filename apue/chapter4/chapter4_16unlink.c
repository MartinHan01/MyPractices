#include "my_apue.h"

char buf[] = "1234567890";

int main(int argc, char const *argv[]) {
	int fd;
	fd = open("tempfile", O_RDWR | O_CREAT, 0755);
	if(fd == -1) {
		perror("open");
		exit(1);
	}
	if(write(fd, buf,strlen(buf)) == -1) {
		printf("write failed\n");
	} else {
		printf("write success\n");
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
	if(write(fd, buf,strlen(buf)) == -1) {
		printf("second write failed\n");
		perror("second write");
	} else {
		printf("second write success\n");
	}
	printf("done\n");
	return 0;
}
