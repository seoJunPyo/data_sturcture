#include <stdio.h>
#include <stdlib.h>


typedef struct tag_DLL_Node
{
	int Data;
	struct tag_DLL_Node* PrevNode;
	struct tag_DLL_Node* NextNode;
} D_Node;

D_Node* DLL_Creat_New_Node(int new_data);
void DLL_Destory_Node(D_Node* Node);
void DLL_Append_Node(D_Node** Head, D_Node* New_Node);
void DLL_Insert_Node_After(D_Node* Current, D_Node* New_Node);
void DLL_Remove_Node(D_Node** Head, D_Node* Target);
D_Node* DLL_Get_Node_At(D_Node* Head, int idx);
int DLL_Get_Node_Count(D_Node* Head);
void DLL_Print_Reverse(D_Node* Head);
