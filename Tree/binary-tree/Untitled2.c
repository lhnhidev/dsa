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

Tree getPrevious(int x, Tree T) {
    Tree predecessor = NULL;
    while (T != NULL) {
        if (x > T->data) {
            predecessor = T;
            T = T->right;
        } else if (x < T->data) {
            T = T->left;
        } else {
            if (T->left != NULL) {
                Tree temp = T->left;
                while (temp->right != NULL) {
                    temp = temp->right;
                }
                return temp;
            }
            break;
        }
    }
    return predecessor; 
}


Tree getNext(int x, Tree T) {
    Tree successor = NULL;
    while (T != NULL) {
        if (x < T->Key) {
            successor = T;
            T = T->Left;
        } else if (x > T->Key) {
            T = T->Right;
        } else {
            if (T->Right != NULL) {
                Tree temp = T->Right;
                while (temp->Left != NULL) {
                    temp = temp->Left;
                }
                return temp;
            }
            break;
        }
    }
    return successor;
}

void printPath(int x, Tree T) {
    while (T != NULL) {
        printf("%d ", T->Key);
        if (x < T->Key) {
            T = T->Left;
        } else if (x > T->Key) {
            T = T->Right;
        } else {
            printf("-> Tim thay\n");
            return;
        }
    }
    printf("-> Khong thay\n");
}

int getHeight(Tree T) {
    if (T == NULL) {
        return -1; 
    } else {
        int leftHeight = getHeight(T->Left);
        int rightHeight = getHeight(T->Right);
        return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
    }
}

// chung 3 cái li?n hnode  
Tree searchNode(int x, Tree T) {
    if (T == NULL || T->Key == x) {
        return T;
    }
    if (x < T->Key) {
        return searchNode(x, T->Left);
    } else {
        return searchNode(x, T->Right);
    }
}

// Hàm tính chi?u cao c?a cây hnode  
int getHeight(Tree T) {
    if (T == NULL) {
        return -1;
    }
    int leftHeight = getHeight(T->Left);
    int rightHeight = getHeight(T->Right);
    return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
}

// Hàm tính chi?u cao c?a nút có khóa x hnode  
int hNode(int x, Tree T) {
    Tree node = searchNode(x, T); // Tìm nút có khóa x trong cây
    if (node == NULL) {
        return -1; // N?u không tìm th?y, tr? v? -1
    } else {
        return getHeight(node); // Tính chi?u cao c?a nút tìm du?c
    }
}



Tree getParent(int x, Tree T) {
    if (T == NULL || T->Key == x) {
        return NULL;
    }

    Tree parent = NULL;
    Tree current = T;

    while (current != NULL) {
        if (x < current->Key) {
            parent = current;
            current = current->Left;
        } else if (x > current->Key) {
            parent = current;
            current = current->Right;
        } else {
            return parent;
        }
    }
    return NULL;
}

int main() {
	
	return 0;
}
