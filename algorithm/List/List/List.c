#include "List.h"

List InitMyList(int size) {
	int i;
	PtrToNode head = (PtrToNode)malloc(sizeof(struct Node));
	PtrToNode tmp = head;
	for (i = 0; i < size; i++) {
		tmp->Next = (PtrToNode)malloc(sizeof(struct Node));
		tmp->Next->Element = i + 1;
		tmp = tmp->Next;
		tmp->Next = NULL;
	}
	return head;
}

List MakeEmpty(List L) {
	return NULL;
}
int IsEmpty(List L) {
	return -1;
}
int IsLast(List L) {
	return -1;
}
Position Find(int X, List L) {
	return NULL;
}
void Delete(int X, List L) {

}
Position FindPrevious(int X, List L) {
	return NULL;
}
void Insert(int X, List L, Position P) {

}
void DeleteList(List L) {

}
Position Header(List L) {
	return NULL;
}
int Retrieve(Position P) {
	return -1;
}

void PrintList(List L) {

	while (L->Next != NULL) {
		printf("%d -> ", L->Next->Element);
		L = L->Next;
	}
	printf("\n");
}