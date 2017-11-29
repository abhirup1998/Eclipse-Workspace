/*
 * Eval.c
 *
 *  Created on: 29-Nov-2017
 *      Author: abhirup
 */
#include <stdio.h>
#include <stdlib.h>
#define LEN 40
typedef struct cstack st;
struct cstack{
	int top;
	char el[LEN];
};
void push(st *stk, char ch)
{
	stk->el[++stk->top] = ch;
}
char peep(st *stk)
{
	return stk->el[stk->top];
}
char pop(st *stk)

{
	return stk->el[stk->top];
	stk->top --;
}
char eval(char a, char b, char ch)
{
	int m = a - 48, n = b - 48;
	switch(ch)
	{
	case '+': return m+n+48;
	case '-': return m-n+48;
	case '*': return m*n+48;
	case '/': return m/n + 48;
	}
}
int prcd(char ch)
{
	switch(ch)
	{
	case '(': return 5;
	case '/': return 4;
	case '*': return 3;
	case '+': return 2;
	case '-': return 1;
	case ')': return 0;
	}
}
int is_symb(char ch)
{
	switch(ch)
	{
		case '(':
		case '/':
		case '*':
		case '+':
		case '-':
		case ')': break;
	}
}
int is_char(char ch)
{
	return (ch >= 97 && ch <=122) || (ch>=65 && ch<=90);
}

st *ost, *sst;
void display()
{
	for(int i = 0; i<= ost->top; i++)
		printf("%c ", ost->el[i]);
	printf("     ");
	for(int i = 0; i<= sst->top; i++)
		printf("%c ", sst->el[i]);
}
int main()
{
	char inf[10];
	int k = 0;
	ost->top = -1; sst->top = -1;
	printf("Enter expr?\n");
	gets(inf);
	printf("%s\n", inf);
	for(int i=0; i<k; i++)
	{
		char ch = inf[i];
		if(is_char(ch))
		{
			push(ost, ch);
		}
		else if(is_symb(ch))
		{
			if(sst->top == -1 || ch == '(')
			{
				push(sst, ch);
				continue;
			}
			char sy = peep(sst);
			if(prcd(ch) <= prcd(sy))
			{
				char res = 48;
				char a = pop(ost), b = pop(ost);
				res = eval(a, b, sy);
				push(ost, res);
			}
			else push(sst, ch);
		}

	}
}
