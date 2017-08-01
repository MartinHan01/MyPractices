#include "my_apue.h"

char buf1[] = "1234567890";
char buf2[] = "abcdefghij";

int main(int argc,char *argv[]) {
	int fd;
	if((fd = open("file.hole", O_RDWR | O_CREAT, 0644)) == -1) {
		perror("open");
	}
	write(fd, buf1, 10);
	lseek(fd, 16384, SEEK_SET);
	write(fd, buf2, 10);
	close(fd);
	return 0;

}
