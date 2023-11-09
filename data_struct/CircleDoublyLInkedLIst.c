#include "CircleDoublyLInkedLIst.h"

CD_Node* CDLL_Creat_New_Node(int new_data)
{
	CD_Node* New_Node = (CD_Node*)malloc(sizeof(CD_Node));

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

void CDLL_Destory_Node(CD_Node* Node)
{
	free(Node);
}

void CDLL_Append_Node(CD_Node** Head, CD_Node* New_Node)
{
	if (*Head == NULL)
	{
		*Head = New_Node;
		(*Head)->NextNode = *Head;
		(*Head)->PrevNode = *Head;
	}
	else
	{
		CD_Node* Tail = (*Head)->PrevNode;
		New_Node->NextNode = *Head;
		New_Node->PrevNode = Tail;

		(*Head)->PrevNode = New_Node;
		Tail->NextNode = New_Node;
	}
}

void CDLL_Insert_Node_After(CD_Node* Current, CD_Node* New_Node)
{
	New_Node->PrevNode = Current;
	New_Node->NextNode = Current->NextNode;

	Current->NextNode = New_Node;
	Current->NextNode->PrevNode = New_Node;
}

void CDLL_Remove_Node(CD_Node** Head, CD_Node* Target)
{
	if (*Head == Target)
	{
		(*Head)->PrevNode->NextNode = Target->NextNode;
		(*Head)->NextNode->PrevNode = Target->PrevNode;
		(*Head) = Target->NextNode;

		Target->NextNode = NULL;
		Target->PrevNode = NULL;
	}
	else
	{
		CD_Node* Temp = Target;

		Target->PrevNode->NextNode = Temp->NextNode;
		Target->NextNode->PrevNode = Temp->PrevNode;

		Target->NextNode = NULL;
		Target->PrevNode = NULL;
	}
}

CD_Node* CDLL_Get_Node_At(CD_Node* Head, int idx)
{
	CD_Node* Current = Head;

	while (Current->NextNode != Head && idx > 0)
	{
		Current = Current->NextNode;
		idx--;
	}

	return Current;
}

int CDLL_Get_Node_Count(CD_Node* Head)
{
	int count = 0;
	CD_Node* Current = Head;

	do
	{
		Current = Current->NextNode;
		count++;
	} while (Current != Head);

	return count;
}
