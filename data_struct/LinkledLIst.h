#include <stdio.h>
#include <stdlib.h>

typedef struct tag_SLL_Node
{
	int Data;
	struct tag_SLL_Node* NextNode;
} S_Node;

typedef struct tag_SLL
{
	S_Node *Head;
	S_Node *Tail;
	int length;
} SLL;

SLL* SLL_Create_List(void);
S_Node* SLL_Create_Node(int new_data);
void SLL_Destory_Node(S_Node* node);
void SLL_Append_Noed(SLL** List, S_Node* New_Node);
S_Node* SLL_Get_Node_At(S_Node* Head, int idx);
void SLL_Remove_Node(SLL** List, S_Node* Target);
void SLL_Insert_Node_After(SLL** List, S_Node* Current, S_Node* New_Node);
int SLL_Get_Node_Count(SLL* List);
void SLL_Insert_New_Head(SLL** List, S_Node* New_Head);