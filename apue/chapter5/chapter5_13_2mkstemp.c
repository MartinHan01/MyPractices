#include "my_apue.h"

void make_temp(char *);

int main(int argc, char *argv[]) {

    char good_template[] = "/tmp/dirXXXXXXXXX";
    char *bad_template = "/tmp/dirXXXXXXXXX";

    printf("trying to create first temp file...\n");
    make_temp(good_template);
    printf("trying to create second temp file...\n");
    make_temp(bad_template);

    return 0;
}

void make_temp(char *template) {
    int fd;
    if((fd = mkstemp(template)) == -1) {
        err_ret("mkstemp");
    }
    printf("temp file create success name = %s\n", template);
    struct stat buf;
    if(stat(template,&buf) == -1) {
        err_ret("stat");
    } else {
        printf("file exist\n");
        close(fd);
        unlink(template);
    }

}