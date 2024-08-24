#include <stdio.h>
#include <stdlib.h>

#define mx 100

typedef int itemType;

typedef struct Queue {
	itemType item[mx];
	int front, rear; 	// front la vi tri dau, rear la vi tri cuoi
} Queue;

// Tao hang doi rong
void makeNullQueue(Queue *q) {
	q->front = -1;
	q->rear = -1;
}

// Kiem tra hang doi co rong khong
int emptyQueue(Queue q) {
	return q.front == -1;
}

// Kiem tra hang doi co full khong
int fullQueue(Queue q) {
	return q.rear - q.front + 1 == mx;
}

// Lay ra phan tu dau cua hang doi
itemType frontQueue(Queue q) {
	if (emptyQueue(q)) {
		return -1;
	}
	return q.item[q.front];
}

// Lay ra phan tu cuoi cua hang doi
itemType rearQueue(Queue q) {
	if (emptyQueue(q)) {
		return -1;
	}
	return q.item[q.rear];
}

// Them vao cuoi hang doi 1 phan tu
void enqueue(itemType x, Queue *q) {
	if (!fullQueue(*q)) {
		if (emptyQueue(*q)) {
			q->front = 0;
		}
		if (q->rear == mx - 1) {
			for (int i = q->front; i <= q->rear; i++) {
				q->item[i - q->front] = q->item[i];
			}
			q->rear = mx - q->front - 1;
			q->front = 0;
		}
	}
	else {
		printf("Hang doi day\n");
		return;
	}
	
	q->rear++;
	q->item[q->rear] = x;
}

// Xoa phan tu dau tien cua hang doi
void dequeue(Queue *q) {
	if (emptyQueue(*q)) {
		printf("Hang doi rong\n");
		return;
	}
	q->front++;
	if (q->front > q->rear) makeNullQueue(q);
}

int main() {
	
	Queue q;
	makeNullQueue(&q);
	
	int n; scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int x; scanf("%d", &x);
		enqueue(x, &q);
	}
	
	while (!emptyQueue(q)) {
		printf("%d ", frontQueue(q));
		dequeue(&q);
	}
	
	return 0;
}

