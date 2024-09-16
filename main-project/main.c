#include <stdio.h>

typedef int ElementType;

#define mx 100

typedef struct Queue {
	ElementType Element[mx];
	int Front;
	int Rear;
} Queue;

void makeNullQueue(Queue *q) {
	q->Front = -1;
	q->Rear = -1;
}

int fullQueue(Queue q) {
	return q.Rear - q.Front + 1 == mx;
}

int emptyQueue(Queue q) {
	return q.Rear == -1;
}

void enQueue(ElementType x, Queue *q) {
	if (fullQueue(*q)) return;
	q->Rear++;
	q->Element[q->Rear] = x;
}

void readQueue(Queue *q) {
	int n; scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		ElementType x; scanf("%d", &x);
		enQueue(x, q);
	}
}

void printQueue(Queue q) {
	if (emptyQueue(q)) return;
	for (int i = q.Front; i <= q.Rear; i++) {
		printf("%d ", q.Element[i]);
	}
}

int main() {
	Queue q; 
	makeNullQueue(&q);
	
	readQueue(&q);
	printQueue(q);
	return 0;
}
