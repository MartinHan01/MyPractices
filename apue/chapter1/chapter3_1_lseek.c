#include "my_apue.h"

int main(int argc, char *argv[]) {
	if(lseek(STDIN_FILENO, 0 ,SEEK_SET) != -1) {
		printf("seek success\n");
	} else {
		printf("cannot seek\n");
	}
	return 0;
}
