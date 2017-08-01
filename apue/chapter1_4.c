#include <stdio.h>
#include <unistd.h>
#include <errno.h>

#define BUFFSIZE 4096

int main(int argc,char *argv[]) {
	int n;
	char buf[BUFFSIZE];
	while((n = read(STDIN_FILENO,buf,BUFFSIZE)) > 0) {
		if(write(STDOUT_FILENO, buf, n) == -1) {
			perror("write");
		}
	}
	return 0;
}
