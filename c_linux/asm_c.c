#include <stdio.h>

static __inline__ void myadd(int i, int *res);

int main(int argc,char *argv[]) {
    int a = 3;
    myadd(1, &a);
    printf("a = %d\n", a);
    return 0;
}

static __inline__ void myadd(int i, int *res) {
    __asm__ __volatile__(
        "addl %1, %0"
        :"=m"(*res)
        :"ir" (1),"m"(*res)
    );
}