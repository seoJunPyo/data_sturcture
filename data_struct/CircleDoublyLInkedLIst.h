#include <stdio.h>
#include <stdlib.h>


typedef struct tag_CDLL_Node
{
	int Data;
	struct tag_CDLL_Node* PrevNode;
	struct tag_CDLL_Node* NextNode;
} CD_Node;

CD_Node* CDLL_Creat_New_Node(int new_data);
void CDLL_Destory_Node(CD_Node* Node);
void CDLL_Append_Node(CD_Node** Head, CD_Node* New_Node);
void CDLL_Insert_Node_After(CD_Node* Current, CD_Node* New_Node);
void CDLL_Remove_Node(CD_Node** Head, CD_Node* Target);
CD_Node* CDLL_Get_Node_At(CD_Node* Head, int idx);
int CDLL_Get_Node_Count(CD_Node* Head);

