#include "LinkledLIst.h"
#include "DoublyLinkedList.h"
#include "CircleDoublyLInkedLIst.h"

void Test_SLL(void);
void Test_DLL(void);
void Test_CDLL(void);

int main(void)
{
	Test_SLL();
	return 0;
}

void Test_SLL(void)
{
	int i = 0, count = 0;
	SLL* List = NULL;
	S_Node* Current = NULL;
	S_Node* New_Node = NULL;

	List = SLL_Create_List();

	for (i = 0; i < 5; i++)
	{
		New_Node = SLL_Create_Node(i);
		SLL_Append_Noed(&List, New_Node);
	}

	New_Node = SLL_Create_Node(-1);
	SLL_Insert_New_Head(&List, New_Node);

	New_Node = SLL_Create_Node(-2);
	SLL_Insert_New_Head(&List, New_Node);

	count = SLL_Get_Node_Count(List);
	for (i = 0; i < count; i++)
	{
		Current = SLL_Get_Node_At(List->Head, i);
		printf("List[%d] : %d\n", i, Current->Data);
	}

	printf("\n [2] 노드 뒤에 3000 삽입...\n\n");

	Current = SLL_Get_Node_At(List->Head, 2);
	New_Node = SLL_Create_Node(3000);

	SLL_Insert_Node_After(&List, Current, New_Node);

	count = SLL_Get_Node_Count(List);
	for (i = 0; i < count; i++)
	{
		Current = SLL_Get_Node_At(List->Head, i);
		printf("List[%d] : %d\n", i, Current->Data);
	}

	printf("\n리스트 제거...\n\n");

	for (i = 0; i < count; i++)
	{
		Current = SLL_Get_Node_At(List->Head, 0);

		if (Current != NULL)
		{
			SLL_Remove_Node(&List, Current);
			SLL_Destory_Node(Current);
		}
	}
}

void Test_DLL(void)
{
	int i = 0, count = 0;
	D_Node* List = NULL;
	D_Node* New_Node = NULL;
	D_Node* Current = NULL;

	for (i = 0; i < 5; i++)
	{
		New_Node = DLL_Creat_New_Node(i);
		DLL_Append_Node(&List, New_Node);
	}

	count = DLL_Get_Node_Count(List);
	for (i = 0; i < count; i++)
	{
		Current = DLL_Get_Node_At(List, i);
		printf("List[%d] : %d\n", i, Current->Data);
	}

	DLL_Print_Reverse(List);

	printf("\n [2] 노드 뒤에 3000 삽입...\n\n");
	Current = DLL_Get_Node_At(List, 2);
	New_Node = DLL_Creat_New_Node(3000);
	DLL_Insert_Node_After(Current, New_Node);

	count = DLL_Get_Node_Count(List);
	for (i = 0; i < count; i++)
	{
		Current = DLL_Get_Node_At(List, i);
		printf("List[%d] : %d\n", i, Current->Data);
	}

	DLL_Print_Reverse(List);

	printf("\n리스트 제거...\n\n");

	for (i = 0; i < count; i++)
	{
		Current = DLL_Get_Node_At(List, 0);

		if (Current != NULL)
		{
			DLL_Remove_Node(&List, Current);
			DLL_Destory_Node(Current);
		}
	}
}

void Test_CDLL(void)
{
	int i = 0, count = 0;
	CD_Node* List = NULL;
	CD_Node* New_Node = NULL;
	CD_Node* Current = NULL;

	for (i = 0; i < 5; i++)
	{
		New_Node = CDLL_Creat_New_Node(i);
		CDLL_Append_Node(&List, New_Node);
	}

	count = CDLL_Get_Node_Count(List);
	for (i = 0; i < count; i++)
	{
		Current = CDLL_Get_Node_At(List, i);
		printf("List[%d] : %d\n", i, Current->Data);
	}


	printf("\n [2] 노드 뒤에 3000 삽입...\n\n");
	Current = CDLL_Get_Node_At(List, 2);
	New_Node = CDLL_Creat_New_Node(3000);
	CDLL_Insert_Node_After(Current, New_Node);

	count = CDLL_Get_Node_Count(List);
	for (i = 0; i < count; i++)
	{
		Current = CDLL_Get_Node_At(List, i);
		printf("List[%d] : %d\n", i, Current->Data);
	}

	printf("\n리스트 제거...\n\n");

	for (i = 0; i < count; i++)
	{
		Current = CDLL_Get_Node_At(List, 0);

		if (Current != NULL)
		{
			CDLL_Remove_Node(&List, Current);
			CDLL_Destory_Node(Current);
		}
	}
}