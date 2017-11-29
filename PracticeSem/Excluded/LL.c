/*
 * LL.c
 *
 *  Created on: 30-Nov-2017
 *      Author: abhirup
 */
#include<stdio.h>
#include<stdlib.h>
typedef struct node {
	int data;
	struct node *next;} Node;
	Node *front,*head1,*head2,*last=NULL;
	int count(){
		Node *t=front;
		int c=0;
		while(t!=NULL){
			t=t->next;

		}
		printf("%d ",c);
		return c;
	}
	void split(){
		int size=count();
		int mid=size/2;
		Node *temp=front;
		head1=front;
		int i=0;
		while(i<mid){
			temp=temp->next;
			i++;
		}
		Node *t=temp->next;
		temp->next=NULL;
		head2=t;
	}
	void search(){
		Node *t=front;
		int x;
		scanf("%d",&x);
		int c=0;
		while(t!=NULL){
			if(t->data==x){
				c=1;
				break;
			}
			t=t->next;
		}
		if(c==1){
			printf("ELEMENT FOUND\n");
		}else{
			printf("ELEMENT NOT FOUND\n");
		}
	}
	void reverse(Node *t){
		if(t==NULL)
			return;
		reverse(t->next);
		printf("%d ",t->data);
	}
	void delete_beg(){
		Node *t=front;
		front=front->next;
		free(t);
	}
	void delete_last(){
		Node *t1,*t2;
		t2=front;
		while(t2->next!=NULL){
			t1=t2;
			t2=t2->next;
		}
		t1->next=NULL;
		free(t2);
	}
	void insert(){
		int pos;
		int x;
		printf("Enter the position\nEnter the number\n");
		scanf("%d",&pos);
		scanf("%d",&x);
		Node *temp=(Node*)malloc(sizeof(Node*));
		temp->data=x;
		Node *t=front;
		if(front==NULL){
			front=temp;
			return;
		}
		if(pos==0){
			temp->next=front;
			front=temp;
		}
		int i=0;
		while(i!=pos-1){
			t=t->next;
			i++;
		}
		Node *next = t->next;
		t->next=temp;
		temp->next=next;
	}
	void insert_beg(){
		printf("Enter a element\n");
		int x;
		scanf("%d",&x);
		Node *temp=(Node*)malloc(sizeof(Node*));
		temp->data=x;
		temp->next=NULL;
		if(front==NULL){
			front=temp;
		}else{
			temp->next=front;
			front=temp;
		}
	}
	void insert_last(){
		printf("Enter a element\n");
		int x;
		scanf("%d",&x);
		Node *temp=(Node*)malloc(sizeof(Node*));
		temp->data=x;
		temp->next=NULL;
		if(front==NULL){
			front=temp;
		}else{
			Node *t=front;
			while(t->next!=NULL){
				t=t->next;
			}
			t->next=temp;
		}}
	void display(){
		Node *t=front;
		while(t!=NULL){
			printf("%d ",t->data);
			t=t->next;
		}
		printf("\n");
	}
	int main(){
		int choice=1;
		printf("Enter 1 to insert from begining\n Enter 2 to insert from end\n Enter 3 to insert at any position\n Enter 4 to display\n Enter 5 to delete from beginning\n Enter 7 to reverse\n Enter 8 to Search for a element\nEnter 9 to count nodes\n");
		while(choice>0){
			scanf("%d",&choice);
			switch(choice){
			case 1:insert_beg(); break;
			case 2:insert_last();break;
			case 3: insert();break;
			case 4: display();break;
			case 5:delete_beg();break;
			case 6: delete_last();break;
			case 7:reverse(front); break;
			case 8:search();break;
			case 9: count();break;
			case 10:split();break;
			}}
		return 0;
	}
