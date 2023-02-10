# include <stdio.h>
# include <stdlib.h>

typedef struct Node{
	int data;
	struct Node *next;
}node;

node *makeNode(){
	node *head = (node*)malloc(sizeof(head));
	node *temp = head;
	int n;
	scanf("%d", &n);
	for(int i=0; i<n; ++i){
		scanf("%d", &temp->data);
		if(n-i==1) temp->next=0;
		else{
			node *tail = (node*)malloc(sizeof(tail));
			temp->next=tail;
			temp = tail;
		}
	}
	return head;
}

void printLL(node *head){
	while(head!=0){
		printf("%d ", head->data);
		head=head->next;
	}printf("\n");
}

void main(){
	node *head = makeNode();
	printLL(head);	
}
