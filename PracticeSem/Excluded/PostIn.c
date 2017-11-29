#include <stdio.h>
#include <string.h>
char st[100];
int top = -1;
void push(char val)
{
	st[++top] = val;
}
char pop()
{
	return st[top--];
}
int isEmpty()
{
	return top == -1;
}
int pref(char c)
{
	switch(c)
	{
	case '^': return 5;
	case '/': return 4;
	case '*': return 3;
	case '+': return 2;
	case '-': return 1;
	default : return 0;
	}
}
void display()
{
	if(isEmpty())
	{
		printf("Stack is empty!\n");
		return;
	}
	int i =0;
	printf("Stack: ");
	for(i = 0; i<= top; i++)
		printf("%c ", st[i]);
	printf("\n");
}
int main()
{
	char inf[100], tmp[100];
	printf("Enter Infix: ");
	gets(tmp);
	int len = strlen(tmp), k = 0, valid =1;
	int flen = len;
	char post[len+2];
	for(int i=1; i<=len; i++)
	{
		inf[i] = tmp[i-1];
	}
	inf[0] = '('; inf[len+1]=')';
	printf("%s of size %d\n", inf, flen);
	int i = 0;
	for (; i < len+2 && valid; i++)
	{

		char ch = inf[i];
		if(ch>64 && ch <91)ch = 'A';
		switch(ch)
		{
		case '(':
			push(ch);
			flen--;
			break;
		case ')':
			flen--;
			if(isEmpty())
			{
				printf("Invalid!");
				valid = 0;
			}
			while(st[top] != '(' && top >= 0)
			{
				post[k++] = pop();
			}
			top--;
			break;
		case '^':
		case '/':
		case '*':
		case '+':
		case '-':
			if( pref(ch) >= pref(st[top]) )
				push(ch);
			else
			{
				post[k++] = pop();
				push(ch);
			}
			break;
		case 'A':
			post[k++] = inf[i];
			break;
		}
		printf("Postfix: %s\n", post);
	}
	for(int i=0; i<flen+2; i++)
		printf("%c", post[i]);

}
