#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>
#include <sys/types.h>
#include <errno.h>

int main(int argc,char *argv[]) {
    DIR *dir;
    struct dirent *dirent;
    if(argc != 2) {
        printf("args must is two");
        exit(1);
    }
    if((dir = opendir(argv[1])) == NULL) {
        perror("can't open dir");
        exit(1);
    }
    while((dirent = readdir(dir)) != NULL) {
        printf("%s ",dirent -> d_name);
    }


    closedir(dir);
    return 0;
}
