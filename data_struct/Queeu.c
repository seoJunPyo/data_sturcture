#include "Queue.h"

// 순환 큐
void CQ_Create_Queue(CircularQueue** Queue, int Capacity)
{
	*Queue = (CircularQueue*)malloc(sizeof(CircularQueue));
	if (*Queue != NULL)
	{
		(*Queue)->Nodes = (CQ_Node*)malloc(sizeof(CQ_Node) * (Capacity + 1));
		(*Queue)->Capacity = Capacity;
		(*Queue)->Front = 0;
		(*Queue)->Rear = 0;
	}
}

void CQ_Destroy_Queue(CircularQueue* Queue)
{
	free(Queue->Nodes);
	free(Queue);
}

void CQ_Enqueue(CircularQueue* Queue, int New_Data)
{
	int Pos = 0;

	if (Queue->Rear == Queue->Capacity)
	{
		Pos = Queue->Rear;
		Queue->Rear = 0;
	}
	else
		Pos = Queue->Rear++;

	Queue->Nodes[Pos].Data = New_Data;
}

int CQ_Dequeue(CircularQueue* Queue)
{
	int Pos = Queue->Front;

	if (Queue->Front == Queue->Capacity)
		Queue->Front = 0;
	else
		Queue->Front++;

	return Queue->Nodes[Pos].Data;
}

int CQ_Get_Size(CircularQueue* Queue)
{
	if (Queue->Rear >= Queue->Front)
		return Queue->Rear - Queue->Front;
	else
		return (Queue->Capacity - Queue->Front) + Queue->Rear + 1;
}

int CQ_IsEmpty(CircularQueue* Queue)
{
	return Queue->Front == Queue->Rear;
}

int CQ_IsFull(CircularQueue* Queue)
{
	if (Queue->Rear > Queue->Front)
		return Queue->Rear - Queue->Front == Queue->Capacity;
	else
		return (Queue->Rear + 1) == Queue->Front;
}

// 링크드 큐
void LQ_Create_Queue(LinkedQueue** Queue)
{
	*Queue = (LinkedQueue*)malloc(sizeof(LinkedQueue));
	if (*Queue != NULL)
	{
		(*Queue)->Front = NULL;
		(*Queue)->Rear = NULL;
		(*Queue)->Count = 0;
	}
}

void LQ_Destroy_Queue(LinkedQueue* Queue)
{
	while (!LQ_IsEmpty(Queue))
	{
		LQ_Node *Popped = LQ_Dequeue(Queue);
		LQ_Destroy_Node(Popped);
	}
	free(Queue);
}

LQ_Node* LQ_Create_Node(char* New_Data)
{
	LQ_Node* New_Node = (LQ_Node*)malloc(sizeof(LQ_Node));
	if (New_Node != NULL)
	{
		New_Node->Data = New_Data;
		New_Node->NextNode = NULL;
	}

	return New_Node;
}

void LQ_Destroy_Node(LQ_Node* Node)
{
	free(Node);
}

void LQ_Enqueue(LinkedQueue* Queue, LQ_Node* New_Node)
{
	if (Queue->Front == NULL)
	{
		Queue->Front = New_Node;
		Queue->Rear = New_Node;
	}
	else
	{
		Queue->Rear->NextNode = New_Node;
		Queue->Rear = New_Node;
	}

	Queue->Count++;
}

LQ_Node * LQ_Dequeue(LinkedQueue* Queue)
{
	LQ_Node * Popped = Queue->Front;

	if (Queue->Front->NextNode == NULL)
	{
		Queue->Front = NULL;
		Queue->Rear = NULL;
	}
	else
		Queue->Front = Queue->Front->NextNode;

	Queue->Count--;

	return Popped;
}

int LQ_Get_Size(LinkedQueue* Queue)
{
	return Queue->Count;
}

int LQ_IsEmpty(LinkedQueue* Queue)
{
	return Queue->Front == NULL;
}