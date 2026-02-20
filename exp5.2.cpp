#include <stdio.h>
#include <stdlib.h>
struct node {
    int data;
    struct node *next;
    struct node *prev;
};
struct node *head = NULL;
void insert_begin(int val) {
    struct node *newnode;
    newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = val;
    newnode->prev = NULL;
    newnode->next = head;
    if(head != NULL)
        head->prev = newnode;
    head = newnode;}
void insert_end(int val) {
    struct node *newnode, *temp;
    newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = val;
    newnode->next = NULL;
    if(head == NULL) {
        newnode->prev = NULL;
        head = newnode;
        return;    }
    temp = head;
    while(temp->next != NULL)
        temp = temp->next;
    temp->next = newnode;
    newnode->prev = temp;}
void insert_pos(int val, int pos) {
    struct node *newnode, *temp;
    int i;

    if(pos <= 0) {
        printf("Invalid Position\n");
        return;
    }

    if(pos == 1) {
        insert_begin(val);
        return;
    }

    temp = head;

for(i = 1; i < pos-1 && temp != NULL; i++)
    temp = temp->next;

if(temp == NULL) {
    printf("Invalid Position\n");
    return;
}
    newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = val;

    newnode->next = temp->next;
    newnode->prev = temp;

    if(temp->next != NULL)
        temp->next->prev = newnode;

    temp->next = newnode;
}


void delete_begin() {
    struct node *temp;
    if(head == NULL) {
        printf("List is empty\n");
        return;    }
    temp = head;
    head = head->next;
    if(head != NULL)
        head->prev = NULL;
    free(temp); }
void delete_end() {
    struct node *temp;
    if(head == NULL) {
        printf("List is empty\n");
        return;    }
    temp = head;
    if(temp->next == NULL) {
        free(temp);
        head = NULL;
        return;    }
    while(temp->next != NULL)
        temp = temp->next;
    temp->prev->next = NULL;
    free(temp); }
void delete_pos(int pos) {
    struct node *temp = head;
    int i;
    if(head == NULL) {
        printf("List is empty\n");
        return;    }
    if(pos == 1) {
        delete_begin();
        return;    }
    for(i = 1; i < pos && temp != NULL; i++)
        temp = temp->next;
    if(temp == NULL) {
        printf("Invalid Position\n");
        return;    }
    if(temp->next != NULL)
        temp->next->prev = temp->prev;
    temp->prev->next = temp->next;
    free(temp);}
void display() {
    struct node *temp = head;
    if(temp == NULL) {
        printf("List is empty\n");
        return;    }
    while(temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;    }
    printf("NULL\n"); }
int main() {
    int choice, val, pos;
    do {
        printf("\n1.Insert Begin 2.Insert End 3.Insert Pos");
        printf("\n4.Delete Begin 5.Delete End 6.Delete Pos");
        printf("\n7.Display 0.Exit\n");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                scanf("%d", &val);
                insert_begin(val);
                break;
            case 2:
                scanf("%d", &val);
                insert_end(val);
                break;
            case 3:
                scanf("%d%d", &val, &pos);
                insert_pos(val, pos);
                break;
            case 4:
                delete_begin();
                break;
            case 5:
                delete_end();
                break;
            case 6:
                scanf("%d", &pos);
                delete_pos(pos);
                break;
            case 7:
                display();
                break;
            case 0:
                break;
            default:
                printf("Invalid choice\n");
        }
    } while(choice != 0);
    return 0;
}

