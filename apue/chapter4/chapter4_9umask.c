#include "my_apue.h"

#define RWRWRW (S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH)

int main(int argc, char const *argv[]) {
	umask(0);
	open("foo", O_CREAT, 0777);
	// creat("foo",RWRWRW);
	umask(S_IWGRP | S_IWOTH | S_IRGRP | S_IROTH);
	// umask(0022);
	// creat("bar",RWRWRW);
	open("bar", O_CREAT, 0777);
	return 0;
}
