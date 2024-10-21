#include <stdio.h>

typedef int ElementType;
typedef int Node;

#define mx 100
#define NIL -999

typedef struct Tree {
	ElementType Data[mx];
	Node Parent[mx];
	int MaxNode;
} Tree;

void makenullTree(Tree *tree) {
	tree->MaxNode = 0;
}

int emptyTree(Tree tree) {
	return tree.MaxNode == 0;
}

Node root(Tree tree) {
	if (emptyTree(tree)) return NIL;
	return 0;
}

Node parent(Node n, Tree tree) {
	if (n < 0 || n > tree.MaxNode-1 || emptyTree(tree)) return NIL;
	return tree.Parent[n];
}

Node label(Node n, Tree tree) {
	if (n < 0 || n > tree.MaxNode-1 || emptyTree(tree)) return NIL;
	return tree.Data[n];
}

Node leftChild(Node n, Tree tree) {
	if (n < 0 || n > tree.MaxNode-1 || emptyTree(tree)) return NIL;
	for (int i = n + 1; i < tree.MaxNode; i++) {
		if (tree.Parent[i] == n) return i;
	}
	return NIL;
}

Node rightSibling(Node n, Tree tree) {
	if (n < 0 || n > tree.MaxNode-1 || emptyTree(tree)) return NIL;
	Node parent = tree.Parent[n];
	for (int i = n + 1; i < tree.MaxNode; i++) {
		if (tree.Parent[i] == parent) {
			return i;
		}
	}
	return NIL;
}

void PreOrder(Node n, Tree tree) {
	if (emptyTree(tree) || n < 0 || n > tree.MaxNode - 1) return;
	printf("%d ", tree.Data[n]);
	Node child = leftChild(n, tree);
	while (child != NIL) {
		PreOrder(child, tree);
		child = leftChild(child, tree);
	}
}

void InOrder(Node n, Tree tree) {
	Node i = leftChild(n, tree);
	if (i != NIL) InOrder(i, tree);
	printf("%d ", label(i, tree));
	i = rightSibling(i, tree);
	while (i != NIL) {
		InOrder(i, tree);
		i = rightSibling(i, tree);
	}
}

void PostOrder(Node n, Tree tree) {
	Node i = leftChild(n, tree);
	while (i != NIL) {
		PostOrder(i, tree);
		i = rightSibling(i, tree);
	}
	printf("%d ", label(n, tree));
}

void readTree(Tree *tree) {
	makenullTree(tree);
	int n; scanf("%d", &n);
	tree->MaxNode = n;
	int root;
	scanf("%d", root);
	tree->Data[0] = root;
	tree->Parent[0] = NIL;
	for (int i = 0; i < tree->MaxNode; i++) {
		printf("Nhap cha cua nut %d: ", i);
		int par; scanf("%d", &par);
		tree->Parent[i] = par;
		printf("Nhap nhan cua nut %d: ", i);
		int label; scanf("%d", &label);
		tree->Data[i] = label;
	}
}

int main() {
	
	Tree tree;
	
	return 0;
}
