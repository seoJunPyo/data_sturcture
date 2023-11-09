#include "DoublyLinkedList.h"

D_Node* DLL_Creat_New_Node(int new_data)
{
	D_Node* New_Node = (D_Node*)malloc(sizeof(D_Node));

	if (New_Node == NULL)
	{
		printf("노드를 만드는데 메모리 공간이 부족합니다.\n");
		exit(EXIT_FAILURE);
	}

	New_Node->Data = new_data;
	New_Node->PrevNode = NULL;
	New_Node->NextNode = NULL;

	return New_Node;
}

void DLL_Destory_Node(D_Node* Node)
{
	free(Node);
}

void DLL_Append_Node(D_Node** Head, D_Node* New_Node)
{
	if (*Head == NULL)
		*Head = New_Node;
	else
	{
		D_Node* Tail = *Head;
		while (Tail->NextNode != NULL)
			Tail = Tail->NextNode;

		Tail->NextNode = New_Node;
		New_Node->PrevNode = Tail;
	}
}

void DLL_Insert_Node_After(D_Node* Current, D_Node* New_Node)
{
	New_Node->NextNode = Current->NextNode;
	New_Node->PrevNode = Current;

	if (Current->NextNode != NULL)
	{
		Current->NextNode->PrevNode = New_Node;
		Current->NextNode = New_Node;
	}
}

void DLL_Remove_Node(D_Node** Head, D_Node* Target)
{
	if (*Head == Target)
	{
		*Head = Target->NextNode;
		if (*Head != NULL)
			(*Head)->PrevNode = NULL;

		Target->NextNode = NULL;
		Target->PrevNode = NULL;
	}
	else
	{
		D_Node* Temp = Target;

		if (Target->NextNode != NULL)
			Target->NextNode->PrevNode = Temp->PrevNode;

		if (Target->PrevNode != NULL)
			Target->PrevNode->NextNode = Temp->NextNode;

		Target->NextNode = NULL;
		Target->PrevNode = NULL;
	}
}

D_Node* DLL_Get_Node_At(D_Node* Head, int idx)
{
	D_Node* Current = Head;

	while (Current->NextNode != NULL && idx > 0)
	{
		Current = Current->NextNode;
		idx--;
	}

	return Current;
}

int DLL_Get_Node_Count(D_Node* Head)
{
	int count = 0;
	D_Node* Current = Head;

	while (Current != NULL)
	{
		Current = Current->NextNode;
		count++;
	}

	return count;
}

void DLL_Print_Node(D_Node* Node)
{
	if (Node->PrevNode == NULL)
		printf("Prev : NULL ");
	else
		printf("Prev : %d ", Node->PrevNode->Data);

	printf("Current : %d ", Node->Data);

	if (Node->NextNode == NULL)
		printf("Next : NULL");
	else 
		printf("Next : %d", Node->NextNode->Data);

	printf("\n");
}

void DLL_Print_Reverse(D_Node* Head)
{
	D_Node *Tail = Head;
	while (Tail->NextNode != NULL)
		Tail = Tail->NextNode;

	while (Tail != NULL)
	{
		printf("%d ", Tail->Data);
		Tail = Tail->PrevNode;
	}

}