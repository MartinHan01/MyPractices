#include "my_apue.h"

int main(int argc,char *argv[]) {
	char buf[MAXLINE];
	pid_t pid;
	int status;
	if(fgets(buf, MAXLINE, stdin) != NULL) {
		if(buf[strlen(buf) - 1] == '\n') {
			buf[strlen(buf) - 1] = 0; // replce end char \n to NULL
		}
	}

	pid = fork();
	if(pid == 0) {
		execlp(buf, buf, NULL);
		exit(127);
	}
	if(waitpid(pid, &status,WUNTRACED) == -1) {
		perror("waitpid");
	}
	return 1;

}
