#include "tree.h"

SearchTree MakeEmpty(SearchTree T) {
	if (T == NULL) {
		return NULL;
	}
	T->Left = MakeEmpty(T->Left);
	T->Right = MakeEmpty(T->Right);
	free(T);
	return NULL;
}
Position Find(int X, SearchTree T) {
	if (T == NULL) {
		return NULL;
	}
	if (X == T->Element) {
		return T;
	}
	Position p;
	p = Find(X, T->Left) != NULL;
	if (p != NULL) {
		return p;
	}
	p = Find(X, T->Right) != NULL;
	if (p != NULL) {
		return p;
	}
}
Position FindMin(SearchTree T) {

}
Position FindMax(SearchTree T) {

}
SearchTree Insert(int X, SearchTree T) {

}
SearchTree Delete(int X, SearchTree T) {

}

void PrintTree(SearchTree T) {
	if (T == NULL) {
		printf("tree is empty\n");
		return;
	}
	PrintTreeDeep(T, 0,High(T));
}

void PrintTreeDeep(SearchTree T, int deep, int high) {
	if (T == NULL) {
		return;
	}
	PrintTreeDeep(T->Left, deep + 1,high);
	int i = 0;
	for (i = 0; i < high - deep - 1; i++) {
		printf("   ");
	}
	printf("%d\n", T->Element);
	PrintTreeDeep(T->Right, deep + 1, high);
}

int High(SearchTree T) {
	if (T == NULL) {
		return 0;
	}
	int left, right,result;
	left = High(T->Left);
	right = High(T->Right);
	result = left > right ? left : right;
	return result + 1;
	
}