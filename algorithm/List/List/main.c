#include <stdio.h>
#include "List.h"



int main(int argc, char *argv[]) {
	List list = InitMyList(10);
	PrintList(list);
	system("pause");
	return 0;
}