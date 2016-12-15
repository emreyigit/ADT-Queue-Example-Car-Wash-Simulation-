#pragma once
struct Car {
	int arrivalTime;
	int startTime;
};

struct Node {

	int arrivalTime;
	int startTime;
	int carNumber;
	int val;
	struct Node *next;

};

struct queueRecord {

	struct Node *front;
	struct Node *rear;
	int size;

};

typedef struct queueRecord *Queue;

Queue CreateQueue(int);
void MakeEmptyQueue(Queue);
int QueueSize(Queue);
void Enqueue(struct Node, Queue);
struct Node Dequeue(Queue);
struct Node* FrontOfQueue(Queue);
int RearOfQueue(Queue);
int IsEmptyQueue(Queue);

