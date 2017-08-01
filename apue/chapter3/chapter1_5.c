#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <stdlib.h>

int main(int argc,char *argv[]) {
	int c;
	while((c = getc(stdin)) != EOF) {
		if((putc(c, stdout)) == EOF) {
			break;
		}
	}
}
