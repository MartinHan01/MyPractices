#include "my_apue.h"
#include <sys/utsname.h>

int main(int argc, char *argv[]) {

    struct utsname name;
    if(uname(&name) == -1) {
        err_ret("uname");
    }
    printf("sysname = %s\n",name.sysname);
    printf("nodename = %s\n",name.nodename);
    printf("release = %s\n",name.release);
    printf("version = %s\n",name.version);
    printf("machine = %s\n",name.machine);

    return 0;
}