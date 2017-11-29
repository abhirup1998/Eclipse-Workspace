/*
 * CQ.c
 *
 *  Created on: 30-Nov-2017
 *      Author: abhirup
 */
#include <stdio.h>
 #define len 5
int que[len];
int front = -1, rear = -1;
void qinsert(int val)
{

	if(front == (rear+1)%len)
	{
		printf("\nOVERFLOW\n");
		return;
	}
	else if (front == -1 && rear == -1)
	{
		front = 0;
	}
	que[(++rear)%len] = val;
}
void qdelete()
{
	if(front == -1)
	{
	printf("\nEMPTY QUEUE!\n");
	return;
	}
	else printf("Popped: %d\n", que[front++]);
}
void display()
{
	int i = 0;
	printf("Queue:   ~front@%d   ~rear@%d\n", front, rear);
	printf("         ");
	int looped = 0;
	looped = (rear >= len)? 1 : 0;
	for( i = front; i <= (looped? len-1 : rear); i++)
	printf("%d ", que[i]);
	for( i = 0; looped && i <= rear%len; i++)
	printf("%d ", que[i]);
	printf("\n");
}
int main()
{
	printf("Menu\n");
	printf("Press 1 to insert @rear\n");
	printf("Press 2 to delete @front\n");
	printf("Press 3 to display\n");
	printf("Press 4 to exit\n");
	int ch = 0;
	do{
		printf("Choice?  ");
		scanf("%d", &ch);
		switch(ch)
		{
		case 1: printf("Value? ");
				int val = 0;
				scanf("%d", &val);
				qinsert(val);
				break;
		case 2: qdelete();
				break;
		case 3: display();break;
		case 4: printf("Exiting operations..\n");
				display();
				continue;
		default: continue;
		}
	} while(ch != 4);

	return 0;
}
