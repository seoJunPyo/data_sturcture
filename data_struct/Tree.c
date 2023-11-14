#include "Tree.h"

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