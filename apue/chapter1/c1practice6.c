#include "my_apue.h"

char buf[] = "1234567890";

int main(int argc, char *argv[]) {
	const char *filename = "test.txt";
	int fd = open(filename, O_RDWR | O_CREAT, 0644);
	write(fd, buf, strlen(buf));
	close(fd);

	fd = open(filename, O_RDWR | O_APPEND);
	lseek(fd , 0, SEEK_SET);
	write(fd, "hello", 5);
	close(fd);

	return 0;
}
