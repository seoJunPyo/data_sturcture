#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct tag_AS_Node
{
	int Data;
} AS_Node;

typedef struct tag_LLS_Node
{
	char* Data;
	struct tag_LLS_Node* NextNode;
} LLS_Node;

typedef struct Stack_Arr
{
	int Capacity;
	int Top; 
	AS_Node* Nodes;
} ArrayStack;

typedef struct Stack_SLL
{
	LLS_Node* List;
	LLS_Node* Top;
} LinkdedListStack;

void AS_Create_Stack(ArrayStack** Stack, int Capacity);
void AS_Destroy_Stack(ArrayStack* Stack);
void AS_Push(ArrayStack* Stack, int New_Data);
int AS_Pop(ArrayStack* Stack);
int AS_Top(ArrayStack* Stack);
int AS_Get_Size(ArrayStack* Stack);
int AS_IsEmpty(ArrayStack* Stack);
int AS_IsFull(ArrayStack* Stack);

void LLS_Create_Stack(LinkdedListStack** Stack);
void LLS_Destroy_Stack(LinkdedListStack* Stack);
LLS_Node* LLS_Create_Node(char* New_Data);
void LLS_Destroy_Node(LLS_Node* Node);
void LLS_Push(LinkdedListStack* Stack, LLS_Node* New_Node);
LLS_Node* LLS_Pop(LinkdedListStack* Stack);
LLS_Node* LLS_Top(LinkdedListStack* Stack);
int LLS_IsEmpty(LinkdedListStack* Stack);
int LLS_Get_Size(LinkdedListStack* Stack);