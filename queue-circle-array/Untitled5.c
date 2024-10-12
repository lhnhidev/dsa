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
	return (q.rear - q.front + 1) % mx == 0;
}

void enQueue(int x, Queue *q) {
	if (!fullQueue(*q)) {
		if (emptyQueue(*q)) {
			q->front = 0;
		}
		q->rear = (q->rear + 1) % mx;
		q->data[q->rear] = x;
	}
} 

void deQueue(Queue *q) {
	if (emptyQueue(*q)) return;
	if (q->front == q->rear) makeNullQueue(q);
	q->front = (q->front + 1) % mx;
}

int main() {
	Queue q;
	makeNullQueue(&q);
	return 0;
}





