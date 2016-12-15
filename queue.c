#include "queue.h"
#include <windows.h>

/*This function initialises the queue*/
Queue CreateQueue(int maxElements)
{
	Queue q;

	q = (struct queueRecord*)malloc(sizeof(struct queueRecord));

	if (q == NULL)
		printf("Error: Out of space!");
	else
		MakeEmptyQueue(q); 

	return q;

}

/*This function sets the queue size to 0, and creates a dummy element
and sets the front and rear point to this dummy element*/
void MakeEmptyQueue(Queue q)
{
	q->size = 0;
	q->front = (struct Node*)malloc(sizeof(struct Node));

	if (q->front == NULL)
		printf("Error: Out of space!");
	else {
		q->front->next = NULL;
		q->rear = q->front;
	}
}

/*Shows if the queue is empty*/
int IsEmptyQueue(Queue q)
{
	if (q->size == 0) 
		return 1;

	else 
		return 0;
}

/*Returns the queue size*/
int QueueSize(Queue q)
{
	return q->size;
}

/*Enqueue - Adds a new element to the queue, simly creates a node and
adds it to the rear of the queue*/
void Enqueue(struct Node x, Queue q)
{
	struct Node *tmp = (struct Node*)malloc(sizeof(struct Node));

	tmp->arrivalTime = x.arrivalTime;
	tmp->startTime = x.startTime;
	tmp->carNumber = x.carNumber;

	tmp->next = NULL;

	q->rear->next = tmp;
	q->rear = tmp;
	q->size++;
	//printf("\n EN QUEU  %d\n\n", q->size);

}

/*Dequeue - Removes a node from the queue, basically removes a node from
the front of the queue*/
struct Node Dequeue(Queue q)
{
	struct Node *tmp = q->front->next;
	int val = tmp->val;


	if (q->size == 1) {

		q->rear->next = q->front->next = NULL;

		q->rear = q->front;

	}
	
	else
		q->front->next = q->front->next->next;

	struct Node rVal;

	rVal.arrivalTime = tmp->arrivalTime;
	rVal.startTime = tmp->startTime;
	rVal.carNumber = tmp->carNumber;
	q->size--;
	free(tmp);
	
	//printf("\n DE QUEU  %d\n\n", q->size);
	return rVal;

}

/*Returns the value stored in the front of the queue*/
struct Node* FrontOfQueue(Queue q)
{
	if (IsEmptyQueue(q)!=1)
		return q->front->next;
	else
	{
		//printf("The queue is empty\n");
		return NULL;
	}
}

/*Returns the value stored in the rear of the queue*/
int RearOfQueue(Queue q)
{
	if (!IsEmptyQueue(q))
		return q->rear->val;
	else
	{
		//printf("The queue is empty\n");
		return -1;
	}
}