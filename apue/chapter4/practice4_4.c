#include "my_apue.h"

#define RWRWRW (S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH)

int main(int argc, char *argv[]) {

    umask(0);
    if(creat("foo",RWRWRW) < 0) {
        perror("creat error");
        exit(-1);
    }

    umask(S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH);

    if(creat("bar",RWRWRW) < 0) {
        perror("creat bar error");
        exit(-1);
    }


    return 0;
}