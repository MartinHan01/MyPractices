#include <stdio.h>

int main(int argc,char *argv[]) {

    const int a = 5;
    int *p = (int *)&a;
    *p = 100;
    printf("a = %d\n", a);

    return 0;
}