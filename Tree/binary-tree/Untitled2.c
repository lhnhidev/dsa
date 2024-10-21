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

Tree search(int x, Tree tree) {
	if (tree == NULL) return NULL;
	if (tree->Data == x) return tree;
	if (tree->Data < x) return search(x, tree->left);
	return search(x, tree->right);
}

void insertTree(int x, Tree *tree) {
	if (*tree == NULL) {
		(*tree) = (Node *)malloc(sizeof(tree));
		(*tree)->Data = x;
		(*tree)->left = NULL;
		(*tree)->right = NULL;
	}
	else {
		if ((*tree)->Data < x) insertTree(x, &(*tree)->right);
		else insertTree(x, &(*tree)->left);
	}
}

int deleteMin(Tree *tree) {
	int k;
	if ((*tree)->left == NULL) {
		k = (*tree)->Data;
		*tree = (*tree)->right;
		return k;
	}
	return DeleteMin((*tree)->left);
}

void deleteNode(int x, Tree *root) {
	if (root != NULL) {
		if (x < (*root)->Data) deleteNode(x, (*root)->left);
		else {
			if (x > (*root)->Data) deleteNode(x, (*root)->right);
			else {
				if (((*root)->left == NULL) && ((*root)->right == NULL)) {
					root = NULL;
				}
				else {
					if ((*root)->left == NULL) root = (*root)->right;
					else {
						if ((*root)->right == NULL) root = (*root)->left;
						else (*root)->Data = deleteMin((*root)->right);
					}
				}
			}
		}
	}
}

int main() {
	
	return 0;
}
