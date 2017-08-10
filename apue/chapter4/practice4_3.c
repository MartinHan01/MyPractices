#include "my_apue.h"

int main(int argc, char *argv[]) {

    int fd;
    char *filename = "testfile";
    if((fd = open(filename, O_RDWR | O_CREAT ,0755)) == -1) {
        perror("open");
        exit(1);
    }
    printf("open success\n");
    if(fchmod(fd, 0111) == -1) {
        perror("fchmod error");
        exit(1);
    }
    printf("fchmod success\n");
    if(close(fd) == -1) {
        perror("close");
        exit(1);
    }
    printf("close success\n");
    if((fd = open(filename, O_RDWR)) == -1) {
        perror("reopen");
        exit(1);
    }
    printf("reopen success\n");
    close(fd);

    return 0;
}