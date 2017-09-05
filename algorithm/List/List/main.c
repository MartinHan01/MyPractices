#include <stdio.h>
#include "List.h"



int main(int argc, char *argv[]) {
	List list = InitMyList(10);
	PrintList(list);
	//MakeEmpty(list);
	//PrintList(list);
	printf("find 5 result is %d\n", Find(5, list));
	Delete(5, list);
	printf("5 is delete \n");
	printf("find 5 result is %d\n", Find(5, list));
	PrintList(list);
	PtrToNode node = FindPrevious(6, list);
	if (node != NULL) {
		printf("position 6 previces is %d\n", node->Element);
	}
	Insert(5, list, node);
	printf("insert success\n");
	PrintList(list);
	printf("reverse list\n");
	Reverse(list);
	PrintList(list);
	DeleteList(list);
	printf("empty list\n");
	PrintList(list);
	system("pause");
	return 0;
}