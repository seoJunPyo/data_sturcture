#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <string.h>
#include <ctype.h>

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

typedef struct tagETNode
{
	struct tagETNode* Left;
	struct tagETNode* Right;
	char Token[256];
} ET_Node;

typedef struct tagDisjoinSet
{
	struct tagDisjoinSet* Parent;
	void* Data;
} DisjoinSet;

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

ET_Node* ET_Create_Node(char *Token);
void ET_Destroy_Node(ET_Node* Node);
void ET_Destory_Tree(ET_Node* Root);
void ET_Preorder_Print_Tree(ET_Node* Root);
void ET_Inorder_Print_Tree(ET_Node* Root);
void ET_Postorder_Print_Tree(ET_Node* Root);
void ET_Build_Expression_Tree(char* Postfix, ET_Node** Node);
double ET_Evaluate(ET_Node* Tree);

DisjoinSet* DS_Make_Set(void* New_Data);
void DS_Destroy_Set(DisjoinSet* Set);
void DS_Union_Set(DisjoinSet* Parent, DisjoinSet* Set);
DisjoinSet* DS_Find_Set(DisjoinSet* Set);