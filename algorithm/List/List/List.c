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
	PtrToNode tmp = L->Next;
	L->Next = NULL;
	PtrToNode p = NULL;
	while (tmp->Next != NULL) {
		p = tmp;
		tmp = tmp->Next;
		free(p);
	}
	return L;
}
int IsEmpty(List L) {
	if (NULL == L) {
		return 0;
	}
	return NULL == L->Next ? 0 : 1;
}
int IsLast(Position P,List L) {
	if (NULL == L) {
		return 0;
	}
	PtrToNode tmp = L ->Next;
	while (NULL != tmp) {
		if (tmp == P) {
			break;
		}
		tmp = tmp->Next;
	}
	if (NULL == tmp) {
		return 0;
	}
	if (tmp->Next == NULL) {
		return 1;
	}
	return 0;
}
Position Find(int X, List L) {
	if (NULL == L) {
		return NULL;
	}
	PtrToNode tmp = L->Next;
	while (NULL != tmp) {
		if (tmp->Element == X) {
			return tmp;
		}
		tmp = tmp->Next;
	}
	return NULL;
}
void Delete(int X, List L) {
	L = L->Next;
	PtrToNode tmp;
	if (NULL == L) {
		return;
	}
	while (NULL != L->Next) {
		if (L->Next->Element == X) {
			tmp = L->Next;
			L->Next = L->Next->Next;
			free(tmp);
		}
		else {
			L = L->Next;
		}
	}
}
Position FindPrevious(int X, List L) {
	PtrToNode p = L->Next;
	if (NULL == p) {
		return NULL;
	}
	while (NULL != p->Next) {
		if (p->Next->Element == X) {
			return p;
		}
		p = p->Next;
	}
	return NULL;
}
void Insert(int X, List L, Position P) {
	PtrToNode tmp = (PtrToNode)malloc(sizeof(struct Node));
	tmp->Element = X;
	L = L->Next;
	if (NULL == L) {
		return;
	}
	while (NULL != L->Next) {
		if (L== P) {
			tmp->Next = L->Next;
			L->Next = tmp;
			break;
		}
		L = L->Next;
	}

}
void DeleteList(List L) {
	if (NULL == L->Next) {
		return;
	}
	PtrToNode head = L;
	PtrToNode tmp;
	while (NULL != L) {
		tmp = L;
		L = L->Next;
		free(tmp);
	}
	head->Next = NULL;
}
void Reverse(List L) {
	PtrToNode p, q, r;
	p = L->Next;
	if (p == NULL) {
		return;
	}
	q = p->Next;
	p->Next = NULL;
	while (q != NULL) {
		r = q->Next;
		q->Next = p;
		p = q;
		q = r;
	}
	L->Next = p;
	return;
}

void PrintList(List L) {
	if (L->Next == NULL) {
		printf("empty\n");
	}
	while (L->Next != NULL) {
		printf("%d -> ", L->Next->Element);
		L = L->Next;
	}
	printf("\n");
}