#include <stdio.h>
#include <stdlib.h>

typedef struct tag_CQ_Node
{
	int Data;
} CQ_Node;

typedef struct tag_LQ_Node
{
	char * Data;
	struct tag_LQ_Node* NextNode;
} LQ_Node;

typedef struct tag_CQ
{
	int Capacity;
	int Front;
	int Rear;
	CQ_Node* Nodes;
} CircularQueue;

typedef struct tag_LQ
{
	LQ_Node* Front;
	LQ_Node* Rear;
	int Count;
} LinkedQueue;

void CQ_Create_Queue(CircularQueue** Queue, int Capacity);
void CQ_Destroy_Queue(CircularQueue* Queue);
void CQ_Enqueue(CircularQueue* Queue, int New_Data);
int CQ_Dequeue(CircularQueue* Queue);
int CQ_Get_Size(CircularQueue* Queue);
int CQ_IsEmpty(CircularQueue* Queue);
int CQ_IsFull(CircularQueue* Queue);

void LQ_Create_Queue(LinkedQueue** Queue);
void LQ_Destroy_Queue(LinkedQueue* Queue);
LQ_Node* LQ_Create_Node(char* New_Data);
void LQ_Destroy_Node(LQ_Node* Node);
void LQ_Enqueue(LinkedQueue* Queue, LQ_Node* New_Node);
LQ_Node* LQ_Dequeue(LinkedQueue* Queue);
int LQ_Get_Size(LinkedQueue* Queue);
int LQ_IsEmpty(LinkedQueue* Queue);