#include <stdio.h>
#include <stdlib.h>

/* Doubly linked node: data, next, prev */
struct DoublyNode {
    int data;
    struct DoublyNode* next;
    struct DoublyNode* prev;
};

struct DoublyNode* head = NULL;

struct DoublyNode* newNode(int data) {
    struct DoublyNode* n = (struct DoublyNode*)malloc(sizeof(struct DoublyNode));
    n->data = data; n->next = NULL; n->prev = NULL;
    return n;
}

/* Insert at beginning */
void insert_at_beginning(int data) {
    struct DoublyNode* n = newNode(data);
    n->next = head;
    if (head != NULL) head->prev = n;  /* old head points back to new */
    head = n;
}

/* Insert at end */
void insert_at_end(int data) {
    struct DoublyNode* n = newNode(data);
    if (head == NULL) { head = n; return; }
    struct DoublyNode* temp = head;
    while (temp->next != NULL) temp = temp->next;
    temp->next = n;
    n->prev = temp;  /* new node's prev = last node */
}

/* Traverse forward */
void traverse_forward() {
    struct DoublyNode* temp = head;
    printf("Forward: ");
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    insert_at_end(10);
    insert_at_end(20);
    insert_at_beginning(5);
    traverse_forward();
    return 0;
}