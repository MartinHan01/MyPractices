#include <stdlib.h>
#include <stdio.h>

#ifndef __Tree_H__

struct TreeNode;
typedef struct TreeNode *Position;
typedef struct TreeNode *SearchTree;

SearchTree MakeEmpty(SearchTree T);
Position Find(int X, SearchTree T);
Position FindMin(SearchTree T);
Position FindMax(SearchTree T);
SearchTree Insert(int X, SearchTree T);
SearchTree Delete(int X, SearchTree T);
void PrintTree(SearchTree T);
void PrintTreeDeep(SearchTree T, int deep,int high);
int High(SearchTree T);

#endif

struct TreeNode {
	int Element;
	SearchTree Left;
	SearchTree Right;
};