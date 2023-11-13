#include "Caculator.h"

char NUMBER[] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '0', '.' };

int IsNumber(char Cipher)
{
	int i = 0;
	int len = sizeof(NUMBER);

	for (i = 0; i < len; i++)
		if (Cipher == NUMBER[i])
			return 1;

	return 0;
}

unsigned int Get_Next_Token(char* Expression, char* Token, int* TYPE)
{
	unsigned int i = 0;

	for (i = 0; 0 != Expression[i]; i++)
	{
		Token[i] = Expression[i];

		if (IsNumber(Expression[i]) == 1)
		{
			*TYPE = OPERAND;

			if (IsNumber(Expression[i + 1]) != 1)
				break;
		}
		else
		{
			*TYPE = Expression[i];
			break;
		}
	}


	Token[++i] = '\0';
	return i;
}

int Get_Priority(char Operator, int InStack)
{
	int Priority = -1;

	switch (Operator)
	{
	case LEFT_PARENTHESIS : 
		if (InStack)
			Priority = 3;
		else
			Priority = 0;
		break;

	case PLUS :
	case MINUS:
		Priority = 2;
		break;

	case MULTIPY:
	case DEVIDE:
		Priority = 1;
		break;
	default:
		break;
	}

	return Priority;
}

int IsPrior(char Operator_In_Stack, char Operator_In_Token)
{
	return Get_Priority(Operator_In_Stack, 1) > Get_Priority(Operator_In_Token, 0);
}

void Get_Postfix(char* InfixExpression, char* PostfixExpression)
{
	char Token[32];
	int Type = -1;
	unsigned int len = strlen(InfixExpression);
	unsigned int Position = 0;
	LinkdedListStack *Stack;

	LLS_Create_Stack(&Stack);

	while (Position < len)
	{
		Position += Get_Next_Token(&InfixExpression[Position], Token, &Type);

		if (Type == OPERAND)
		{
			strcat_s(PostfixExpression, 100, Token);
			strcat_s(PostfixExpression, 100, " ");
		}
		else if (Type == RIGHT_PARENTHESIS)
		{
			while (!LLS_IsEmpty(Stack))
			{
				LLS_Node* Popped = LLS_Pop(Stack);

				if (Popped->Data[0] == LEFT_PARENTHESIS)
				{
					LLS_Destroy_Node(Popped);
					break;
				}
				else
				{
					strcat_s(PostfixExpression, 100, Popped->Data);
					LLS_Destroy_Node(Popped);
				}
			}
		}
		else
		{
			while (!LLS_IsEmpty(Stack) && !IsPrior(LLS_Top(Stack)->Data[0], Token[0]))
			{
				LLS_Node *Popped = LLS_Pop(Stack);

				if (Popped->Data[0] != LEFT_PARENTHESIS)
					strcat_s(PostfixExpression, 100, Popped->Data);

				LLS_Destroy_Node(Popped);
			}

			LLS_Push(Stack, LLS_Create_Node(Token));
		}
		
	}

	while (!LLS_IsEmpty(Stack))
	{
		LLS_Node* Popped = LLS_Pop(Stack);

		if (Popped->Data[0] != LEFT_PARENTHESIS)
			strcat_s(PostfixExpression, 110, Popped->Data);

		LLS_Destroy_Node(Popped);
	}

	LLS_Destroy_Stack(Stack);
}

double Calcuate(char* PostfixExpression)
{
	int len = strlen(PostfixExpression);
	int Read = 0;
	char Token[32];
	int Type = -1;
	double Result;
	
	LLS_Node *Result_Node;
	LinkdedListStack* Stack;
	LLS_Create_Stack(&Stack);

	while (Read < len)
	{
		Read += Get_Next_Token(&PostfixExpression[Read], Token, &Type);
		

		if (Type == SPACE)
			continue;

		if (Type == OPERAND)
		{
			LLS_Push(Stack, LLS_Create_Node(Token));
		}
		else
		{
			char ResultString[32];
			double Operate1, Operate2, TempResult = 0;
			LLS_Node* Node;

			Node = LLS_Pop(Stack);
			Operate2 = atof(Node->Data);
			LLS_Destroy_Node(Node);

			Node = LLS_Pop(Stack);
			Operate1 = atof(Node->Data);
			LLS_Destroy_Node(Node);

	
			switch (Type)
			{
			case PLUS :
				TempResult = Operate1 + Operate2;
				break;
			case MINUS:
				TempResult = Operate1 - Operate2;
				break;
			case MULTIPY:
				TempResult = Operate1 * Operate2;
				break;
			case DEVIDE:
				TempResult = Operate1 / Operate2;
				break;
			}
			_gcvt_s(ResultString, 32, TempResult, 10);
			LLS_Push(Stack, LLS_Create_Node(ResultString));
		}
	}

	Result_Node = LLS_Pop(Stack);
	Result = atof(Result_Node->Data);
	LLS_Destroy_Node(Result_Node);

	LLS_Destroy_Stack(Stack);

	return Result;
}

