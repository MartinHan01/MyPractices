#include "my_apue.h"

char buf[] = "hello martinhan";
char buf_copy[] = "hello martinhan this is copy";

int main(int argc,char *argv[]) {
	int fd1, fd2;
	fd1 = open("test.txt",O_RDWR | O_CREAT , 0644);
	if(fd1 == -1) {
		perror("open");
		exit(1);
	}
	write(fd1,buf, strlen(buf));
	char filename[255];
	sprintf(filename, "/dev/fd/%d" ,fd1);
	fd2 = open(filename, O_RDWR | O_APPEND);
	write(fd2, buf_copy, strlen(buf_copy));

	return 0;
}
