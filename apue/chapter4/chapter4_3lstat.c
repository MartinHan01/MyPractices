#include "my_apue.h"

int main(int argc, char const *argv[]) {
	if(argc == 1) {
		printf("must has a file\n");
		exit(1);
	}
	struct stat buf;
	int i;
	for(i = 1 ; i < argc; i++) {
		if(lstat(argv[i], &buf) == -1) {
			perror("lstat");
			continue;
		}
		if(S_ISREG(buf.st_mode)) {
			printf("regular file\n");
		} else if(S_ISDIR(buf.st_mode)) {
			printf("directory\n");
		} else if(S_ISCHR(buf.st_mode)) {
			printf("character device\n" );
		} else if(S_ISBLK(buf.st_mode)) {
			printf("block device\n" );
		} else if(S_ISFIFO(buf.st_mode)) {
			printf("fifo file\n" );
		} else if(S_ISLNK(buf.st_mode)) {
			printf("symbolic link file\n");
		} else if(S_ISSOCK(buf.st_mode)) {
			printf("socket\n" );
		}
	}
	return 0;
}
