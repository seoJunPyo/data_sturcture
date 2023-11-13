#include "Stack.h"

// 배열기반 스택
void AS_Create_Stack(ArrayStack** Stack, int Capacity)
{
	(*Stack) = (ArrayStack*)malloc(sizeof(ArrayStack));
	if (*Stack == NULL)
	{
		printf("메모리가 부족합니다.");
		exit(EXIT_FAILURE);
	}

	(*Stack)->Nodes = (AS_Node*)malloc(Capacity * sizeof(AS_Node));
	(*Stack)->Top = -1;
	(*Stack)->Capacity = Capacity;
}

void AS_Destroy_Stack(ArrayStack* Stack)
{
	free(Stack->Nodes);
	free(Stack);
}

void AS_Push(ArrayStack* Stack, int New_Data)
{
	Stack->Top++;
	Stack->Nodes[Stack->Top].Data = New_Data;

	if (AS_IsFull(Stack))
	{
		AS_Node* New_Nodes;
		Stack->Capacity = (int)(Stack->Capacity * 1.3);
		New_Nodes = (AS_Node*)malloc(sizeof(AS_Node) * Stack->Capacity);

		if (New_Nodes == NULL)
		{
			printf("더 이상 메모리 공간이 없습니다.\n");
			return;
		}

		for (int i = 0; i < AS_Get_Size(Stack); i++)
			New_Nodes[i] = Stack->Nodes[i];

		Stack->Nodes = New_Nodes;
	}
}

int AS_Pop(ArrayStack* Stack)
{
	int Position = Stack->Top--;
	int size = AS_Get_Size(Stack);
	int Poppded_Data = Stack->Nodes[Position].Data;

	if (size <= Stack->Capacity * 0.7)
	{
		AS_Node* New_Nodes;
		New_Nodes = (AS_Node*)malloc(sizeof(AS_Node) * size);
		Stack->Capacity = size;
	
		for (int i = 0; i < size; i++)
			New_Nodes[i] = Stack->Nodes[i];

		Stack->Nodes = New_Nodes;
	}

	return Poppded_Data;
}

int AS_Top(ArrayStack* Stack)
{
	return Stack->Nodes[Stack->Top].Data;
}

int AS_Get_Size(ArrayStack* Stack)
{
	return Stack->Top + 1;
}

int AS_IsEmpty(ArrayStack* Stack)
{
	return (Stack->Top == -1);
}

int AS_IsFull(ArrayStack * Stack)
{
	return (Stack->Top == Stack->Capacity);
}


// 링크드 리스트 기반 스택

void LLS_Create_Stack(LinkdedListStack** Stack)
{
	(*Stack) = (LinkdedListStack*)malloc(sizeof(LinkdedListStack));

	if (*Stack == NULL)
	{
		printf("메모리가 부족합니다.");
		exit(EXIT_FAILURE);
	}
	(*Stack)->List = NULL;
	(*Stack)->Top = NULL;
}

void LLS_Destroy_Stack(LinkdedListStack* Stack)
{
	while (!LLS_IsEmpty(Stack))
	{
		LLS_Node* Popped = LLS_Pop(Stack);
		LLS_Destroy_Node(Popped);
	}

	free(Stack);
}

LLS_Node* LLS_Create_Node(char* New_Data)
{
	LLS_Node *New_Node = (LLS_Node*)malloc(sizeof(LLS_Node));
	if (New_Node == NULL)
	{
		printf("메모리가 부족합니다.");
		exit(EXIT_FAILURE);
	}

	size_t size = strlen(New_Data) + 1;
	New_Node->Data = (char*)malloc(size);
	if (New_Node->Data == NULL)
	{
		printf("메모리가 부족합니다.");
		exit(EXIT_FAILURE);
	}
	strcpy_s(New_Node->Data, size, New_Data);

	New_Node->NextNode = NULL;

	return New_Node;
}

void LLS_Destroy_Node(LLS_Node* Node)
{
	free(Node->Data);
	free(Node);
}

void LLS_Push(LinkdedListStack* Stack, LLS_Node* New_Node)
{
	if (Stack->List == NULL)
	{
		Stack->List = New_Node;
	}
	else
	{
		Stack->Top->NextNode = New_Node;
	}

	Stack->Top = New_Node;
}

LLS_Node* LLS_Pop(LinkdedListStack* Stack)
{
	LLS_Node *Top_Node = Stack->Top;

	if (Stack->List == Stack->Top)
	{
		Stack->List = NULL;
		Stack->Top = NULL;
	}
	else
	{
		LLS_Node* Current = Stack->List;
		while (Current != NULL && Current->NextNode != Stack->Top)
			Current = Current->NextNode;

		if (Current != NULL)
		{
			Stack->Top = Current;
			Stack->Top->NextNode = NULL;
		}
	}

	return Top_Node;
}

LLS_Node* LLS_Top(LinkdedListStack* Stack)
{
	return Stack->Top;
}

int LLS_IsEmpty(LinkdedListStack* Stack)
{
	return (Stack->List == NULL);
}

int LLS_Get_Size(LinkdedListStack* Stack)
{
	int size = 0;
	LLS_Node* Current = Stack->List;

	while (Current != NULL)
	{
		Current = Current->NextNode;
		size++;
	}
	return size;
}