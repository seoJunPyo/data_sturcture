#include "LinkledLIst.h"

SLL * SLL_Create_List(void)
{
	SLL* New_List = (SLL*)malloc(sizeof(SLL));

	if (New_List == NULL)
	{
		printf("리스트를 만드는데 메모리 공간이 부족합니다.\n");
		exit(EXIT_FAILURE);
	}

	New_List->Head = NULL;
	New_List->Tail = NULL;
	New_List->length = 0;

	return New_List;
}

S_Node* SLL_Create_Node(int new_data)
{
	S_Node* New_Node = (S_Node*)malloc(sizeof(S_Node));

	if (New_Node == NULL)
	{
		printf("노드를 만드는데 메모리 공간이 부족합니다.\n");
		exit(EXIT_FAILURE);
	}

	New_Node->Data = new_data;
	New_Node->NextNode = NULL;

	return New_Node;
}

void SLL_Destory_Node(S_Node* Node)
{
	free(Node);
}

void SLL_Append_Noed(SLL** List, S_Node* New_Node)
{
	if ((*List)->Head == NULL)
	{
		(*List)->Head = New_Node;
		(*List)->Tail = New_Node;
	}
	else
	{
		(*List)->Tail->NextNode = New_Node;
		(*List)->Tail = New_Node;
	}

	(*List)->length++;
}

S_Node* SLL_Get_Node_At(S_Node* Head, int idx)
{
	S_Node* Current = Head;

	while (Current->NextNode != NULL && idx > 0)
	{
		Current = Current->NextNode;
		idx--;
	}

	return Current;
}

void SLL_Remove_Node(SLL** List, S_Node* Target)
{
	if ((*List)->Head == Target)
		(*List)->Head = Target->NextNode;

	else
	{

		S_Node* Current = (*List)->Head;

		while (Current != NULL && Current->NextNode != Target)
			Current = Current->NextNode;

		if (Current != NULL)
		{
			Current->NextNode = Target->NextNode;;
			(*List)->Tail = Current;
		}
	}

	(*List)->length--;
}

void SLL_Insert_Node_After(SLL** List, S_Node* Current, S_Node* New_Node)
{
	New_Node->NextNode = Current->NextNode;
	Current->NextNode = New_Node;
	(*List)->length++;
}

void SLL_Insert_Node_Before(SLL** List, S_Node* Current, S_Node* New_Node)
{
	if ((*List)->Head == NULL)
		(*List)->Head = New_Node;

	else if ((*List)->Head == Current)
		SLL_Insert_New_Head(List, New_Node);

	else
	{
		S_Node* Prev = (*List)->Head;

		while (Prev != NULL && Prev->NextNode != Current)
			Prev = Prev->NextNode;

		if (Prev != NULL)
		{
			Prev->NextNode = New_Node;
			New_Node->NextNode = Current;
		}
	}

	(*List)->length++;
}

int SLL_Get_Node_Count(SLL* List)
{
	return List->length;
}

void SLL_Insert_New_Head(SLL** List, S_Node* New_Head)
{
	if ((*List)->Head == NULL)
		(*List)->Head = New_Head;	
	else
	{
		New_Head->NextNode = (*List)->Head;
		(*List)->Head = New_Head;
	}

	(*List)->length++;
}