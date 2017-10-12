#include "tree.h"
#include <stdio.h>
#include <stdlib.h>

SearchTree InitTree();

int main(int argc, char *argv[]) {

	SearchTree tree = InitTree();
	printf("High:%d\n", High(tree));
	PrintTree(tree);

	printf("find 3 element position is  %p \n", Find(6, tree));

	printf("make empty tree\n");
	tree = MakeEmpty(tree);
	PrintTree(tree);

	system("pause");
	return 0;
}

SearchTree InitTree() {
	Position p1 = (Position)malloc(sizeof(struct TreeNode));
	Position p2 = (Position)malloc(sizeof(struct TreeNode));
	Position p3 = (Position)malloc(sizeof(struct TreeNode));
	Position p4 = (Position)malloc(sizeof(struct TreeNode));
	Position p5 = (Position)malloc(sizeof(struct TreeNode));
	Position p6 = (Position)malloc(sizeof(struct TreeNode));
	Position p7 = (Position)malloc(sizeof(struct TreeNode));
	p1->Element = 1;
	p2->Element = 2;
	p3->Element = 3;
	p4->Element = 4;
	p5->Element = 5;
	p6->Element = 6;
	p7->Element = 7;
	p1->Left = p2;
	p1->Right = p3;
	p2->Left = p4;
	p2->Right = p5;
	p3->Left = p6;
	p3->Right = p7;
	p4->Left = NULL;
	p4->Right = NULL;
	p5->Left = NULL;
	p5->Right = NULL;
	p6->Left = NULL;
	p6->Right = NULL;
	p7->Left = NULL;
	p7->Right = NULL;
	return p1;
}