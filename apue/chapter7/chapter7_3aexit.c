#include "my_apue.h"

static void my_exit1(void);
static void my_exit2(void);

int main(int argc,char *argv) {
    if(atexit(my_exit1) == -1) {
        err_ret("atexit exit1\n");
    }
    if(atexit(my_exit1) == -1) {
        err_ret("atexit exit1\n");
    }
    if(atexit(my_exit2) == -1) {
        err_ret("atexit exit2\n");
    }
    printf("main function is done\n");
    return 0;
}


static void my_exit1(void) {
    printf("call my_exit1\n");
}

static void my_exit2(void) {
    printf("call my_exit2\n");
}