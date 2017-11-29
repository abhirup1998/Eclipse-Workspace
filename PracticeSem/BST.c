/*
 * BST.c
 *
 *  Created on: 29-Nov-2017
 *      Author: abhirup
 */
#include <stdio.h>
#include <stdlib.h>
typedef struct Node node;
struct Node{
	int data;
	struct Node *l, *r;
};
node* allocate()
{
	return (node*)malloc(sizeof(node*));
}
void insert(node* o, node* ptr)
{
	if(ptr == NULL)
	{
		ptr = o;
		printf("Inserted at Head\n");
		return;
	}
	if(o->data < ptr->data)
	{
		printf("%d l> ", ptr->data);
		if(ptr->l == NULL)
			ptr->l = o;
		else
			insert(o, ptr->l);
	}
	else if(o->data > ptr->data)
	{
		printf("%d r> ", ptr->data);
		if(ptr->r == NULL)
			ptr->r = o;
		else
			insert(o, ptr->r);
	}
	else
		printf("Already present\n");
}
void inorder(node *ptr)
{
	if(ptr == NULL)
		return;
	inorder(ptr->l);
	printf("%d ", ptr->data);
	inorder(ptr->r);
}
node* search(node *ptr, int key)
{
	if(ptr == NULL)
	{
		printf("Not found!\n");
		return NULL;
	}
	if(key == ptr->data)
	{
		printf("Found!\n");
		return ptr;
	}
	else if(key < ptr->data)
		search(ptr->l, key);
	else search(ptr->r, key);
}
node* minValueNode(node *ptr)
{
	node* par=allocate();
	while(ptr->l != NULL)
	{

		ptr = ptr->l;
	}
	return ptr;
}
void delete(node *head, int key)
{
	node *ptr = head, *par = NULL;
	while(ptr != NULL)
	{
		if(ptr->data == key)
		{
			printf("Found!\n");
			break;
		}
		par = ptr;
		if(key < ptr->data)
			ptr = ptr->l;
		else ptr = ptr->r;
	}
	if(ptr == NULL) {
		printf("Not found!\n");
		return;
	}
	node *re = allocate(), *repar = allocate();
	int d = 0;
	if(par->r == ptr)d=1;
	else d=0;
	if(ptr->l == NULL && ptr->r == NULL)
	{
		printf("Here at leaf %d.\n", ptr->data);
		if(d == 1)
			par->r = NULL;
		else
			par->l = NULL;
		free(ptr);
		return;
	}
	if(ptr->l != NULL && ptr->r != NULL)
	{
		printf("Fork @%d\n", ptr->data);
		re = minValueNode(ptr->r);
		int dat = re->data;
		printf("Re: @%d\n", re->data);
		delete(ptr, re->data);
		printf("Deleted re \n");
		ptr->data = dat;
	}
	else if(par->l == ptr)
	{
		par->l = ptr->l != NULL? ptr->l : ptr->r;
		free(ptr);
	}
	else if(par->r == ptr)
	{
		par->r = ptr->l != NULL? ptr->l : ptr->r;
		free(ptr);
	}
}
int main()
{
	node *head = NULL; head=allocate();
	head->l = NULL; head->r = NULL;
	int n;
	scanf("%d", &n);
	n--;
	scanf("%d", &head->data);
	for(int i=1; i<=n; i++)
	{
		int dat=0;
		scanf("%d", &dat);
		node *o = allocate();
		o->data = dat; o->l = NULL; o->r=NULL;
		insert(o, head);
		printf("%d\n", dat);
	}
	int key=0;
	printf("\nDisplay In Sorted Order..");
	inorder(head);
	while(key != -1)
	{
		printf("\nEnter key to be searched:");
		scanf("%d", &key);
		search(head, key);
	}key=0;
	while(key != -1)
	{
		printf("\nEnter key to be deleted:");
		scanf("%d", &key);
		delete(head, key);
		inorder(head);
	}
}
