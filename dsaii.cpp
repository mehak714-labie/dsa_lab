#include <stdio.h>
#include <stdlib.h>
struct node {
    int data;
    struct node *next; };
struct node *top = NULL;
// PUSH Operation
void push(int val) {
    struct node *newnode;
    newnode = (struct node*)malloc(sizeof(struct node));
    if(newnode == NULL) {
        printf("Stack Overflow\n");
        return;    }
    newnode->data = val;
    newnode->next = top;
    top = newnode;
    printf("Inserted %d\n", val);}
// POP Operation
void pop() {
    struct node *temp;
    if(top == NULL) {
        printf("Stack Underflow\n");
        return;    }
    temp = top;
    printf("Deleted %d\n", top->data);
    top = top->next;
    free(temp);}
// DISPLAY Operation
void display() {
    struct node *temp = top;
    if(temp == NULL) {
        printf("Stack is empty\n");
        return;
    }
    printf("Stack elements are:\n");
    while(temp != NULL) {
        printf("%d\n", temp->data);
        temp = temp->next;    }}
int main() {
    int choice, val;
    do {
        printf("\n1.Push 2.Pop 3.Display 0.Exit\n");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &val);
                push(val);
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            case 0:
                break;
            default:
                printf("Invalid choice\n");        }
    } while(choice != 0);
    return 0;}

