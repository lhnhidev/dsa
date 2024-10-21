#include <stdio.h>
#include <malloc.h>

typedef int DataType;

typedef struct Node {
	DataType data;
	struct Node *left;
	struct Node *right;
} Node;

typedef Node* Tree;

void makenullTree(Tree *tree) {
	tree = NULL;
}

void insertNode(int x, Tree *tree) {
	if (*tree == NULL) {
		*tree = (Tree)malloc(sizeof(struct Node));
		(*tree)->data = x;
		(*tree)->left = NULL;
		(*tree)->right = NULL;
	}
	else {
		if (x > (*tree)->data) insertNode(x, &(*tree)->right);
		if (x < (*tree)->data) insertNode(x, &(*tree)->left);
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

int main() {
	Tree T=NULL;
	Tree p;
	int x;
	
	insertNode(27,&T);
	insertNode(12,&T);
	insertNode(40,&T);
	insertNode(4,&T);
	insertNode(20,&T);
	insertNode(34,&T);
	insertNode(30,&T); 
	insertNode(50,&T); 
	x=12;
	
	p = getPrevious(x,T);
	if (p==NULL)
	   printf("%d khong co nut dung truoc",x);
	else printf("Nut dung truoc la %d",p->data);
	return 0;
}
