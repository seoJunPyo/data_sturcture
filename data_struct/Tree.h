#include <stdio.h>
#include <stdlib.h>

typedef struct tagLCRSNode
{
	struct tagLCRSNode* LeftChild;
	struct tagLCRSNode* RigthSibling;
	char Data;
} LCRS_Node;

typedef struct tageSBTNode
{
	struct tageSBTNode* Left;
	struct tageSBTNode* Right;
	char Data;
} SBT_Node;

LCRS_Node* LCRS_Create_Node(char New_Data);
void LCRS_Destroy_Node(LCRS_Node* Node);
void LCRS_Destroy_Tree(LCRS_Node* Root);
void LCRS_Add_Child_Node(LCRS_Node* Parent, LCRS_Node* Child);
void LCRS_Print_Tree(LCRS_Node* Node, int Depth);

SBT_Node* SBT_Create_Node(char New_Data);
void SBT_Destroy_Node(SBT_Node* Node);
void SBT_Destroy_Tree(SBT_Node* Node);
void SBT_Preorder_Print_Tree(SBT_Node* Node);
void SBT_Inorder_Print_Tree(SBT_Node* Node);
void SBT_Postorder_Print_Tree(SBT_Node* Node);