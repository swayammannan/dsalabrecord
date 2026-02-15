#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* next;
};
void insert_at_beginning(struct Node** head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = *head;
    *head = newNode;
}
void insert_at_end(struct Node** head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if(*head == NULL) {
        *head = newNode;
        return;
    }

    struct Node* temp = *head;
    while(temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}
void delete_node(struct Node** head, int data) {
    struct Node* temp = *head;
    struct Node* prev = NULL;
    if(temp != NULL && temp->data == data) {
        *head = temp->next;
        free(temp);
        return;
    }
    while(temp != NULL && temp->data != data) {
        prev = temp;
        temp = temp->next;
    }
    if(temp == NULL) return;

    prev->next = temp->next;
    free(temp);
}
void traverse(struct Node* head) {
    struct Node* temp = head;
    while(temp != NULL) {
     printf("%d -> ", temp->data);
    temp = temp->next;
    }
    printf("NULL\n");
}
int main() {
struct Node* head = NULL;
insert_at_beginning(&head, 10);
insert_at_end(&head, 20);
insert_at_end(&head, 30);
traverse(head);
delete_node(&head, 20);
traverse(head);
return 0;
}