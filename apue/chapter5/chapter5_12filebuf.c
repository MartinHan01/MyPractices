#include "my_apue.h"

void    pr_stdio(const char *,FILE *);
int     is_unbuffered(FILE *);
int     is_linebuffered(FILE *);
int     buffer_size(FILE *);

int main(int argc, char *argv[]) {
    FILE *fp;
    fputs("enter any character\n", stdout);
    if(getchar() == EOF) {
        err_ret("getchar error");
    }
    fputs("one line to standard error\n", stderr);
    pr_stdio("stdin", stdin);
    pr_stdio("stdout", stdout);
    pr_stdio("stderr", stderr);
    if((fp = fopen("/etc/passwd", "r")) == NULL) {
        err_ret("fopen error");
    }
    if(getc(fp) == EOF) {
        err_ret("getc error");
    }
    pr_stdio("/etc/passwd", fp);
    return 0;
}

void pr_stdio(const char *fname, FILE *f) {
    printf("stream is %s, ", fname);
    if(is_unbuffered(f)) {
        printf("unbuffered, ");
    } else if(is_linebuffered(f)) {
        printf("line buffered, ");
    } else {
        printf("fully buffered");
    }
    printf("buffer size = %d\n",buffer_size(f));
    
}

int is_unbuffered(FILE *f) {
    return (f->_flags & _IO_UNBUFFERED);
}
int is_linebuffered(FILE *f) {
    return (f->_flags & _IO_LINE_BUF);
}
int buffer_size(FILE *f) {
    return (f->_IO_buf_end - f->_IO_buf_base);
}