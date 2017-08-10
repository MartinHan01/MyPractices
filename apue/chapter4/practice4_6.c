#include "my_apue.h"

int main(int argc, char *argv[]) {

    int f1,f2, len = 0,size = 0;
    char buf[BUFFSIZE],newbuf[BUFFSIZE];

    if(argc != 3) {
        printf("must has src filename and copy filename\n");
        exit(-1);
    }
    if((f1 = open(argv[1], O_RDONLY)) == -1) {
        err_ret("open");
    }
    if((f2 = open(argv[2], O_RDWR | O_CREAT, 0755)) == -1) {
        err_ret("open");
    }
    while((len = read(f1, buf, BUFFSIZE)) != 0) {
        memset(newbuf,0,BUFFSIZE);
        size = 0;
        for(int i = 0 ; i < len ;i++) {
            if(buf[i] != '\0') {
                newbuf[size++] = buf[i];
            }
        }
        write(f2, newbuf,size);
    }


    close(f1);
    close(f2);


    return 0;
}