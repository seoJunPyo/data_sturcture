#include "LinkledLIst.h"
#include "DoublyLinkedList.h"
#include "CircleDoublyLInkedLIst.h"
#include "Caculator.h"
#include "Queue.h"
#include "Tree.h"

void Test_SLL(void);
void Test_DLL(void);
void Test_CDLL(void);
void Test_AS(void);
void Test_LLS(void);
void Test_Calcular(void);
void Test_CQ(void);
void Test_LQ(void);
void Test_LCRS_Tree(void);
void Test_SBT(void);
void Test_ET(void);
void Test_DS(void);

int main(void)
{
	Test_DS();
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

void Test_CQ(void)
{
	int i;
	CircularQueue *Queue;

	CQ_Create_Queue(&Queue, 10);

	CQ_Enqueue(Queue, 1);
	CQ_Enqueue(Queue, 2);
	CQ_Enqueue(Queue, 3);
	CQ_Enqueue(Queue, 4);

	for (int i = 0; i < 3; i++)
	{
		printf("Dequeue : %d ", CQ_Dequeue(Queue));
		printf("Front : %d, Rear : %d\n", Queue->Front, Queue->Rear);
	}

	i = 100;
	while (CQ_IsFull(Queue) == 0)
	{
		CQ_Enqueue(Queue, i++);
	}

	printf("Capacity : %d, Size : %d\n", Queue->Capacity, CQ_Get_Size(Queue));

	while (CQ_IsEmpty(Queue) == 0)
	{
		printf("Dequeue : %d ", CQ_Dequeue(Queue));
		printf("Front : %d, Rear : %d\n", Queue->Front, Queue->Rear);
	}

	CQ_Destroy_Queue(Queue);
}

void Test_LQ(void)
{
	LQ_Node* Popped;
	LinkedQueue* Queue;

	LQ_Create_Queue(&Queue);

	LQ_Enqueue(Queue, LQ_Create_Node("abc"));
	LQ_Enqueue(Queue, LQ_Create_Node("def"));
	LQ_Enqueue(Queue, LQ_Create_Node("efg"));
	LQ_Enqueue(Queue, LQ_Create_Node("hij"));
	
	printf("Queue Size : %d\n", LQ_Get_Size(Queue));

	while (LQ_IsEmpty(Queue) == 0)
	{
		Popped = LQ_Dequeue(Queue);
		printf("Dequeue : %s \n", Popped->Data);
		LQ_Destroy_Node(Popped);
	}

	LQ_Destroy_Queue(Queue);
}

void Test_LCRS_Tree(void)
{
	LCRS_Node* Root = LCRS_Create_Node('A');
	LCRS_Node* B = LCRS_Create_Node('B');
	LCRS_Node* C = LCRS_Create_Node('C');
	LCRS_Node* D = LCRS_Create_Node('D');
	LCRS_Node* E = LCRS_Create_Node('E');
	LCRS_Node* F = LCRS_Create_Node('F');
	LCRS_Node* G = LCRS_Create_Node('G');
	LCRS_Node* H = LCRS_Create_Node('H');
	LCRS_Node* I = LCRS_Create_Node('I');
	LCRS_Node* J = LCRS_Create_Node('J');
	LCRS_Node* K = LCRS_Create_Node('K');

	LCRS_Add_Child_Node(Root, B);
	LCRS_Add_Child_Node(B, C);
	LCRS_Add_Child_Node(B, D);
	LCRS_Add_Child_Node(D, E);
	LCRS_Add_Child_Node(D, F);

	LCRS_Add_Child_Node(Root, G);
	LCRS_Add_Child_Node(G, H);

	LCRS_Add_Child_Node(Root, I);
	LCRS_Add_Child_Node(I, J);
	LCRS_Add_Child_Node(J, K);

	LCRS_Print_Tree(Root, 0);

	LCRS_Destroy_Tree(Root);
}

void Test_SBT(void)
{
	SBT_Node* A = SBT_Create_Node('A');
	SBT_Node* B = SBT_Create_Node('B');
	SBT_Node* C = SBT_Create_Node('C');
	SBT_Node* D = SBT_Create_Node('D');
	SBT_Node* E = SBT_Create_Node('E');
	SBT_Node* F = SBT_Create_Node('F');
	SBT_Node* G = SBT_Create_Node('G');

	A->Left = B;
	B->Left = C;
	B->Right = D;

	A->Right = E;
	E->Left = F;
	E->Right = G;

	printf("Preorder ...\n");
	SBT_Preorder_Print_Tree(A);
	printf("\n");

	printf("Inorder ...\n");
	SBT_Inorder_Print_Tree(A);
	printf("\n");

	printf("Postorder ...\n");
	SBT_Postorder_Print_Tree(A);
	printf("\n");

	SBT_Destroy_Tree(A);
}

void Test_ET(void)
{
	ET_Node* Root = NULL;
	char Postfix[20] = "11 22+ 55*";
	
	ET_Build_Expression_Tree(Postfix, &Root);

	printf("Preorder ...\n");
	ET_Preorder_Print_Tree(Root);
	printf("\n\n");

	printf("Inorder ...\n");
	ET_Inorder_Print_Tree(Root);
	printf("\n\n");

	printf("Postorder ...\n");
	ET_Postorder_Print_Tree(Root);
	printf("\n\n");

	printf("Result : %f \n", ET_Evaluate(Root));

	ET_Destory_Tree(Root);
}

void Test_DS(void)
{
	int a = 1, b = 2, c = 3, d = 4;
	DisjoinSet* Set1 = DS_Make_Set(&a);
	DisjoinSet* Set2 = DS_Make_Set(&b);
	DisjoinSet* Set3 = DS_Make_Set(&c);
	DisjoinSet* Set4 = DS_Make_Set(&d);

	printf("Set1 == Set2 : %d\n", DS_Find_Set(Set1) == DS_Find_Set(Set2));

	DS_Union_Set(Set1, Set3);
	printf("Set1 == Set3 : %d\n", DS_Find_Set(Set1) == DS_Find_Set(Set3));

	DS_Union_Set(Set3, Set4);
	printf("Set3 == Set4 : %d\n", DS_Find_Set(Set3) == DS_Find_Set(Set4));
}