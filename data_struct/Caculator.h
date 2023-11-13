#include <stdlib.h>
#include "Stack.h"

typedef enum
{
	LEFT_PARENTHESIS = '(',
	RIGHT_PARENTHESIS = ')',
	PLUS = '+',
	MINUS = '-',
	MULTIPY = '*',
	DEVIDE = '/',
	SPACE = ' ',
	OPERAND
} SYMBOL;

int IsNumber(char Cipher);
unsigned int Get_Next_Token(char* Expression, char* Token, int* TYPE);
int Get_Priority(char Operator, int InStack);
int IsPrior(char Operator1, char Operator2);
void Get_Postfix(char* InfixExpression, char* PostfixExpression);
double Calcuate(char* PostfixExpression);