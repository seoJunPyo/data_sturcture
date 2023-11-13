#include "LinkledLIst.h"
#include "DoublyLinkedList.h"
#include "CircleDoublyLInkedLIst.h"
#include "Caculator.h"

void Test_SLL(void);
void Test_DLL(void);
void Test_CDLL(void);
void Test_AS(void);
void Test_LLS(void);
void Test_Calcular(void);

int main(void)
{
	Test_AS();
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

void Test_AS(void)
{
	int i = 0;
	ArrayStack* Stack = NULL;

	AS_Create_Stack(&Stack, 10);

	AS_Push(Stack, 3);
	AS_Push(Stack, 37);
	AS_Push(Stack, 11);
	AS_Push(Stack, 12);
	AS_Push(Stack, 12);

	AS_Push(Stack, 3);
	AS_Push(Stack, 37);
	AS_Push(Stack, 11);
	AS_Push(Stack, 12);
	AS_Push(Stack, 12);
	

	printf("Capacity : %d, Size : %d, Top : %d\n\n", Stack->Capacity, AS_Get_Size(Stack), AS_Top(Stack));
	for (i = 0; i < 4; i++)
	{
		if (AS_IsEmpty(Stack))
			break;

		printf("Popped %d ", AS_Pop(Stack));

		if (!AS_IsEmpty(Stack))
			printf("Current Top : %d\n", AS_Top(Stack));
		else
			printf("Stack is Empty.\n");
	}

	AS_Destroy_Stack(Stack);
}

void Test_LLS(void)
{
	int i = 0;
	int Count = 0;
	LLS_Node* Popped;

	LinkdedListStack* Stack;
	LLS_Create_Stack(&Stack);

	LLS_Push(Stack, LLS_Create_Node("abc"));
	LLS_Push(Stack, LLS_Create_Node("def"));
	LLS_Push(Stack, LLS_Create_Node("efg"));
	LLS_Push(Stack, LLS_Create_Node("hij"));

	Count = LLS_Get_Size(Stack);
	printf("Size : %d, Top : %s\n\n", Count, Stack->Top->Data);

	for (i = 0; i < 4; i++)
	{
		if (LLS_IsEmpty(Stack))
			break;

		Popped = LLS_Pop(Stack);
		printf("Popped : %s ", Popped->Data);

		LLS_Destroy_Node(Popped);

		if (!LLS_IsEmpty(Stack))
		{
			printf("Current Top : %s\n", LLS_Top(Stack)->Data);
		}
		else
			printf("Stack is Empty.\n");
	}

	LLS_Destroy_Stack(Stack);
}

void Test_Calcular(void)
{
	char Infix[100];
	char Postfix[200];

	double Result = 0;

	memset(Infix, 0, sizeof(Infix));
	memset(Postfix, 0, sizeof(Infix));

	printf("Enter Infix Expression : ");
	scanf_s("%s", Infix, 100);

	Get_Postfix(Infix, Postfix);

	printf("Infix : %s\nPostfix : %s\n", Infix, Postfix);

	Result = Calcuate(Postfix);
	printf("Calculation Result : %f\n", Result);
}