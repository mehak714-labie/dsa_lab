//single linked list insertation and deleteion
#include <stdio.h>
#include <stdlib.h>
struct node {
	int data ;
	struct node*next;
};
struct node *head = NULL; 

void insert_begin(int val){
	struct node*newnode;
	newnode=(struct node*)malloc(sizeof(struct node));
	newnode->data=val;
	newnode->next=head;
	head=newnode;
	return;} 
	
void insert_end(int val){
	struct node*newnode,*temp;
	newnode=(struct node*)malloc(sizeof(struct node));
	newnode->data=val;	
	newnode->next=NULL;
	if( head== NULL){
		head=newnode;
		return;	}
	temp=head;
	while(temp->next !=NULL)
	temp=temp->next;
	temp->next=newnode;}
	
void insert_pos(int val, int pos){ 
    struct node *newnode, *temp;
    int i;                           
    newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = val;
    if(pos == 1){
        newnode->next = head;
        head = newnode;
        return;    }
    temp = head;
    for(i = 1; i < pos-1 && temp != NULL; i++)
        temp = temp->next;
        if(temp == NULL){
        printf("Invalid position\n");   
        return;    }
    newnode->next = temp->next;   
    temp->next = newnode;        }

void delete_begin(){
	struct node*temp;
	if(head==NULL){
		printf("list is empty");
		return;	}
    temp=head;
        head = head->next;
    free(temp);}

void delete_end(){
struct node *temp, *prev = NULL;
	if(head==NULL){
			printf("list is empty");
		return;	}
	if(head->next==NULL){
		free(head);
		head=NULL;
		return;}
	temp=head;
	while(temp->next!=NULL){
		prev=temp;
		temp=temp->next;	}
	prev->next=NULL;
	free(temp);}
    
void delete_pos(int pos){   
    struct node *temp = head, *prev = NULL;
    int i;
    if(head == NULL){
        printf("List is Empty\n");
        return;    }
    if(pos == 1){
        delete_begin();
        return;    }
    for(i = 1; i < pos && temp != NULL; i++){
        prev = temp;
        temp = temp->next;    }
    if(temp == NULL){
        printf("Invalid Position\n");
        return;    }
    prev->next = temp->next;
    free(temp);}

void display() {
    struct node *temp = head;
    if (temp == NULL) {
        printf("List is empty\n");
        return;    }
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;    }
    printf("NULL\n");   }

int main(){		
int choice, val, pos;
do{
printf("\n1.Insert Begin 2.Insert End 3.Insert Pos");
printf("\n4.Delete Begin 5.Delete End 6.Delete Pos");
printf("\n7.Display 0.Exit");
scanf("%d", &choice);
switch(choice) {
case 1: scanf("%d", &val); insert_begin(val); break;
case 2: scanf("%d", &val); insert_end(val); break;
case 3: scanf("%d%d", &val, &pos); insert_pos(val,pos); break;
case 4: delete_begin(); break;
case 5: delete_end(); break;
case 6: scanf("%d", &pos); delete_pos(pos); break;
case 7: display(); break;
default:
    printf("Invalid choice\n");}    } 
	while(choice != 0);
    return 0;}
