#include <stdio.h>
#include <malloc.h>

typedef int DataType;
typedef struct Node {
	DataType Data;
	struct Node* left;
	struct Node* right;
} Node;

typedef struct Node* Tree;

void makenullTree(Tree *tree) {
	*tree = NULL;
}

int emptyTree(Tree tree) {
	return tree == NULL;
}

Tree leftChild(Tree tree) {
	if (tree == NULL) return NULL;
	return tree->left;
}

Tree rightChild(Tree tree) {
	if (tree == NULL) return NULL;
	return tree->right;
}

int isLeaf(Tree leaf) {
	if (leaf == NULL) return 0;
	return leftChild(leaf) == NULL && rightChild(leaf) == NULL;
}

int soNut(Tree tree) {
	return 1 + soNut(leftChild(tree)) + soNut(rightChild(tree));
}

Tree Create2(DataType v, Tree l, Tree r) {
	Tree N;
	N = (struct Node *)malloc(sizeof(struct Node));
	N->Data = v;
	N->left = l;
	N->right = r;
	return N;
}

void PreOrder(Tree tree) {
	if (tree != NULL) {
		printf("%d ", tree->Data);
		PreOrder(leftChild(tree));
		PreOrder(rightChild(tree));
	}
}

void InOrder(Tree tree) {
	if (tree != NULL) {
		InOrder(leftChild(tree));
		printf("%d ", tree->Data);
		InOrder(rightChild(tree));
	}
}

void PosOrder(Tree tree) {
	if (tree != NULL) {
		PosOrder(leftChild(tree));
		PosOrder(rightChild(tree));
		printf("%d ", tree->Data);
	}
}

int main() {
	
	return 0;
}
