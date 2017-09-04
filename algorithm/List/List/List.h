#pragma once
#include <stdio.h>
#include <stdlib.h>

struct Node;
typedef struct Node *PtrToNode;
typedef PtrToNode List;
typedef PtrToNode Position;

List InitMyList(int size);
List MakeEmpty(List L);
int IsEmpty(List L);
int IsLast(Position P,List L);
Position Find(int X, List L);
void Delete(int X, List L);
Position FindPrevious(int X, List L);
void Insert(int X, List L, Position P);
void DeleteList(List L);
Position Header(List L);
int Retrieve(Position P);
void PrintList(List L);

struct Node {
	int Element;
	Position Next;
};