#include "my_apue.h"

int main(int argc,char *argv[]) {

    if(chdir("/tmp") < 0) {
        perror("chdir failed");
        exit(1);
    }
    printf("chdir to /tmp successed\n");
    return 0;
} 