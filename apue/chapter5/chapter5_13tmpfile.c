#include "my_apue.h"

int main(int argc, char *argv[]) {
    char name[L_tmpnam], line[MAXLINE];
    printf("first tmp name is (%s)\n",tmpnam(NULL));
    printf("second tmp name is (%s)\n",tmpnam(name));
    printf("name = %s\n", name);

    FILE* f;
    f = tmpfile();
    printf("tmp file name is %d", f->_flags);
    fputs("one two three four",f);

    rewind(f);
    while(fgets(line, MAXLINE, f) != NULL) {
        printf("line is %s \n",line);
    }
    
    fclose(f);

    return 0;
}