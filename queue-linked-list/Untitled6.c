#include <stdio.h>
#include <malloc.h>

typedef int ElementType;

typedef struct Node {
	ElementType data;
	struct Node* next;
} Node;

typedef Node* Position;

typedef struct Queue {
	Position rear;
	Position front;
} Queue;

void makeNullQueue(Queue *q) {
	Position header = (Position)malloc(sizeof(Node));
	header->next = NULL;
	q->front = header;
	q->rear = header;
}

int emptyQueue(Queue q) {
	return q.front == q.rear;
}

void enQueue(int x, Queue *q) {
	Position newNode = (Position)malloc(sizeof(Node));
	newNode->data = x;
	newNode->next = NULL;
	q->rear->next = newNode;
	q->rear = q->rear->next;
}

void deQueue(Queue *q) {
	if (emptyQueue(*q)) return;
	q->front = q->front->next;
}

int main() {
	Queue q;
	makeNullQueue(&q);
	
	return 0;
}




