#include "Tree.h"


static char NUMBER[] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '0', '.' };

LCRS_Node* LCRS_Create_Node(char New_Data)
{
	LCRS_Node* New_Node = (LCRS_Node*)malloc(sizeof(LCRS_Node));
	if (New_Node != NULL)
	{
		New_Node->Data = New_Data;
		New_Node->LeftChild = NULL;
		New_Node->RigthSibling = NULL;
	}

	return New_Node;
}

void LCRS_Destroy_Node(LCRS_Node* Node)
{
	free(Node);
}

void LCRS_Destroy_Tree(LCRS_Node* Root)
{
	if (Root->RigthSibling != NULL)
		LCRS_Destroy_Tree(Root->RigthSibling);

	if (Root->LeftChild != NULL)
		LCRS_Destroy_Tree(Root->LeftChild);

	Root->LeftChild = NULL;
	Root->RigthSibling = NULL;

	LCRS_Destroy_Node(Root);
}

void LCRS_Add_Child_Node(LCRS_Node* Parent, LCRS_Node* Child)
{
	if (Parent->LeftChild == NULL)
		Parent->LeftChild = Child;
	else
	{
		LCRS_Node* Current_Child = Parent->LeftChild;
		while (Current_Child->RigthSibling != NULL)
			Current_Child = Current_Child->RigthSibling;

		Current_Child->RigthSibling = Child;
	}
}

void LCRS_Print_Tree(LCRS_Node* Node, int Depth)
{
	int i = 0;
	for (i = 0; i < Depth - 1; i++)
		printf("   ");

	if (Depth > 0)
		printf("+--");

	printf("%c\n", Node->Data);

	if (Node->LeftChild != NULL)
		LCRS_Print_Tree(Node->LeftChild, Depth + 1);
	if (Node->RigthSibling != NULL)
		LCRS_Print_Tree(Node->RigthSibling, Depth);
}


// 이진 트리
SBT_Node* SBT_Create_Node(char New_Data)
{
	SBT_Node* New_Node = (SBT_Node*)malloc(sizeof(SBT_Node));
	if (New_Node != NULL)
	{
		New_Node->Data = New_Data;
		New_Node->Right = NULL;
		New_Node->Left = NULL;
	}

	return New_Node;
}

void SBT_Destroy_Node(SBT_Node* Node)
{
	free(Node);
}

void SBT_Preorder_Print_Tree(SBT_Node* Node)
{
	if (Node == NULL)
		return;

	printf(" %c", Node->Data);

	SBT_Preorder_Print_Tree(Node->Left);
	SBT_Preorder_Print_Tree(Node->Right);
}

void SBT_Inorder_Print_Tree(SBT_Node* Node)
{
	if (Node == NULL)
		return;

	SBT_Inorder_Print_Tree(Node->Left);
	printf(" %c", Node->Data);
	SBT_Inorder_Print_Tree(Node->Right);
}

void SBT_Postorder_Print_Tree(SBT_Node* Node)
{
	if (Node == NULL)
		return;

	SBT_Postorder_Print_Tree(Node->Left);
	SBT_Postorder_Print_Tree(Node->Right);
	printf(" %c", Node->Data);
}

void SBT_Destroy_Tree(SBT_Node* Node)
{
	if (Node == NULL)
		return;

	SBT_Destroy_Tree(Node->Left);
	SBT_Destroy_Tree(Node->Right);
	SBT_Destroy_Node(Node);
}


// 연산 트리
ET_Node* ET_Create_Node(char* Token)
{
	ET_Node* New_Node = (ET_Node*)malloc(sizeof(ET_Node));
	if (New_Node != NULL)
	{
		strncpy_s(New_Node->Token, 256, Token, 256);
		New_Node->Right = NULL;
		New_Node->Left = NULL;
	}

	return New_Node;
}

void ET_Destroy_Node(ET_Node* Node)
{
	free(Node);
}

void ET_Destory_Tree(ET_Node* Root)
{
	if (Root == NULL)
		return;

	ET_Destory_Tree(Root->Left);
	ET_Destory_Tree(Root->Right);
	ET_Destroy_Node(Root);
}

void ET_Preorder_Print_Tree(ET_Node* Root)
{
	if (Root == NULL)
		return;

	printf(" %s", Root->Token);
	ET_Preorder_Print_Tree(Root->Left);
	ET_Preorder_Print_Tree(Root->Right);
}

void ET_Inorder_Print_Tree(ET_Node* Root)
{
	if (Root == NULL)
		return;

	printf("(");
	ET_Inorder_Print_Tree(Root->Left);
	printf(" %s", Root->Token);
	ET_Inorder_Print_Tree(Root->Right);
	printf(")");
}

void ET_Postorder_Print_Tree(ET_Node* Root)
{
	if (Root == NULL)
		return;

	ET_Postorder_Print_Tree(Root->Left);
	ET_Postorder_Print_Tree(Root->Right);
	printf(" %s", Root->Token);
}

static int IsNumber(char Cipher)
{
	int i = 0;
	int len = sizeof(NUMBER);

	for (i = 0; i < len; i++)
		if (Cipher == NUMBER[i])
			return 1;

	return 0;
}

int Get_Token(char* Buffer, char* Postfix)
{
	int len = (int)strlen(Postfix);
	int idx = 0;
	char temp;

	if (!IsNumber(Postfix[len - 1]))
	{
		Buffer[0] = Postfix[len - 1];
		Buffer[1] = '\0';
		return 1;
	}

	while (IsNumber(Postfix[len - idx - 1]))
	{
		Buffer[idx] = Postfix[len - idx - 1];
		idx++;
	}

	for (int i = 0; i < idx / 2; i++)
	{
		temp = Buffer[i];
		Buffer[i] = Buffer[idx - 1 - i];
		Buffer[idx - 1 - i] = temp;
	}

	Buffer[idx] = '\0';

	return idx;
}

void ET_Build_Expression_Tree(char* Postfix, ET_Node** Node)
{
	int len = (int)strlen(Postfix);
	char Token[256];
	int offset = Get_Token(Token, Postfix);
	Postfix[len - offset] = '\0';

	printf("Token : %s\n", Token);

	switch (Token[0])
	{
	case '+' :
	case '-' :
	case '*' :
	case '/':
		(*Node) = ET_Create_Node(Token);
		ET_Build_Expression_Tree(Postfix, &(*Node)->Right);
		ET_Build_Expression_Tree(Postfix, &(*Node)->Left);
		break;
	case ' ':
		ET_Build_Expression_Tree(Postfix, Node);
		break;
	default:
		(*Node) = ET_Create_Node(Token);
		break;
	}
}

double ET_Evaluate(ET_Node* Tree)
{
	double Left = 0, Right = 0, Result = 0;

	if (Tree == NULL)
		return 0;

	switch (Tree->Token[0])
	{
	case '+':
	case '-':
	case '*':
	case '/':
		Right = ET_Evaluate(Tree->Right);
		Left = ET_Evaluate(Tree->Left);

		if (Tree->Token[0] == '+')
			Result = Left + Right;
		else if (Tree->Token[0] == '-')
			Result = Left - Right;
		else if (Tree->Token[0] == '*')
			Result = Left * Right;
		else if (Tree->Token[0] == '/')
			Result = Left / Right;
		break;
	default:
		Result = atof(Tree->Token);
		break;
	}

	return Result;
}


// 분리 집합
DisjoinSet* DS_Make_Set(void* New_Data)
{
	DisjoinSet* New_Set = (DisjoinSet*)malloc(sizeof(DisjoinSet));
	if (New_Set != NULL)
	{
		New_Set->Data = New_Data;
		New_Set->Parent = NULL;
	}
}

void DS_Destroy_Set(DisjoinSet* Set)
{
	free(Set);
}

void DS_Union_Set(DisjoinSet* Parent, DisjoinSet* Set)
{
	Set = DS_Find_Set(Set);
	Set->Parent = Parent;
}

DisjoinSet* DS_Find_Set(DisjoinSet* Set)
{
	while (Set->Parent != NULL)
		Set = Set->Parent;

	return Set;
}