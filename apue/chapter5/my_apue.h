#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define BUFFSIZE 4096
#define MAXLINE  4096

void err_ret(char *);

void err_ret(char *str) {
    perror(str);
    exit(1);
}