#include "my_apue.h"

int main(int argc, char *argv[]) {

    time_t t;
    struct tm *tmp;

    char buf1[16];
    char buf2[64];

    time(&t);
    tmp = localtime(&t);

    if(strftime(buf1, 16, "time and date : %r, %a,%Y-%m-%d %H:%M:%S",tmp) == 0) {
        perror("some error");
    } else {
        printf("buf1 : %s\n", buf1);
    }

    if(strftime(buf2, 64, "time and date : %r, %a,%Y-%m-%d %H:%M:%S",tmp) == 0 ) {
        perror("strftime");
    } else {
        printf("buf2 : %s\n", buf1);
    }



    return 0;
}