#include <stdio.h>

#define mx 100

typedef int ElementType;

typedef struct Queue {
	ElementType data[mx];
	int front, rear;
} Queue;

void makeNullQueue(Queue *q) {
	q->front = -1;
	q->rear = -1;
}

int emptyQueue(Queue q) {
	return q.front == -1;
}

int fullQueue(Queue q) {
	return q.rear - q.front + 1 == mx;
}

void deQueue(Queue *q) {
	if (emptyQueue(*q)) return;
	q->front++;
	if (q->front > q->rear) makeNullQueue(q);
}

void enQueue(int x, Queue *q) {
	if (fullQueue(*q)) return;
	if (q->rear == mx) {
		for (int i = q->front; i <= q->rear; i++) {
			q->data[i - q->front] = q->data[i];
		}
		q->rear = mx - q->front - 1;
		q->front = 0;
	}
	q->data[q->rear + 1] = x;
	q->rear++;
}

int main() {
	Queue q;
	makeNullQueue(&q);
	return 0;
}






