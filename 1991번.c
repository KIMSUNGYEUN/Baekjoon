#include <stdio.h>
#include <stdlib.h>

typedef char BTData;

typedef struct _bTreeNode
{
	BTData data;
	struct _bTreeNode* left;
	struct _bTreeNode* right;
} BTreeNode;

BTreeNode* MakeBTreeNode(BTData data) {
	BTreeNode* nd = (BTreeNode*)malloc(sizeof(BTreeNode));
	nd->data = data;
	nd->left = NULL;
	nd->right = NULL;
	return nd;
}

BTreeNode* SearchTree(BTreeNode* bt, BTData data) {
	if (bt != NULL) {
		if (bt->data == data)
			return bt;
		else {
			BTreeNode* btt = SearchTree(bt->left, data);
			if (btt != NULL) {
				return btt;
			}
			return SearchTree(bt->right, data);
		}
	}
	return NULL;
}

void SetData(BTreeNode* bt, BTData data, BTData data2, BTData data3)
{
	bt->data = data;
	if (data2 != '.')
	{
		bt->left = MakeBTreeNode(data2);
	}
	if (data3 != '.')
	{
		bt->right = MakeBTreeNode(data3);
	}
}

void InorderTraverse(BTreeNode* bt)
{
	if (bt == NULL)
		return;
	InorderTraverse(bt->left);
	printf("%c", bt->data);
	InorderTraverse(bt->right);
}

void PreorderTraverse(BTreeNode* bt)
{
	if (bt == NULL)
		return;
	printf("%c", bt->data);
	PreorderTraverse(bt->left);
	PreorderTraverse(bt->right);
}

void PostorderTraverse(BTreeNode* bt)
{
	if (bt == NULL)
		return;
	PostorderTraverse(bt->left);
	PostorderTraverse(bt->right);
	printf("%c", bt->data);
}

int main(void)
{
	int n;
	BTreeNode* bt = MakeBTreeNode(NULL);
	BTreeNode* btt;

	scanf("%d", &n);
	getchar();
	for (int i = 0; i < n; i++) {
		char a1, a2, a3;
		scanf("%c %c %c", &a1, &a2, &a3);
		getchar();
		btt = SearchTree(bt, a1);
		if (btt != NULL)
			SetData(btt, a1, a2, a3);
		else
			SetData(bt, a1, a2, a3);
	}
	PreorderTraverse(bt);
	printf("\n");
	InorderTraverse(bt);
	printf("\n");
	PostorderTraverse(bt);
	return 0;
}
