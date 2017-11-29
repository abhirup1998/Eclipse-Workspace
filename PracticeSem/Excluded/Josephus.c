#include<stdio.h>
#include<stdlib.h>
typedef struct Node{int data;struct Node* next;}node;
node* head;

node* allocate(){
	return (node*)malloc(sizeof(node));
}

 int main()
 {
 	node* head=allocate();
 	head->data=1;
 	head->next=NULL;
 	printf("Enter no of participants:\n");
 	int n,i;
 	scanf("%d",&n);
 	node* temp=head;
 	for(i=2;i<=n;i++)
 	{
		node* ptr = allocate();
		temp->next=ptr;
 		ptr->data=i;
 		ptr->next=head;
 		temp->next=ptr;
 		temp=ptr;
 	}
 	int k;
 	printf("Enter key:\n");
 	scanf("%d",&k);
 	node* ptr;
 	while(n!=1)
 	{
 		for(i=0;i<k-1;i++)
 			temp=temp->next;
		printf("deleted %d\n",temp->next->data);
 		temp->next = temp->next->next;
 		n--;
 	}
 	printf("Winner is %d ",temp->data);
 	return 0;
}
