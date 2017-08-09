#include "my_apue.h"

int main(int argc, char *argv[]) {

    char ptr[256];
    size_t size;
    if(chdir("/tmp") < 0) {
        perror("chdir failed");
        exit(1);
    }
    // ptr = path_alloc(&size);
    if(getcwd(ptr, size) == NULL) {
        perror("getcwd");
    }
    printf("cwd = %s\n", ptr);

    return 0;
}