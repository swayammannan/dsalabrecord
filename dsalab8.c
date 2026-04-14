#include <stdio.h>
#include <stdlib.h>

struct CircularNode { int data; struct CircularNode* next; };
struct CircularNode* head = NULL;

/* Insert at beginning */
void insert_at_beginning(int data) {
    struct CircularNode* n = (struct CircularNode*)malloc(sizeof(struct CircularNode));
    n->data = data;
    if (head == NULL) {
        n->next = n;   /* points to itself */
        head = n;
        return;
    }
    /* Find last node (the one whose next = head) */
    struct CircularNode* last = head;
    while (last->next != head) last = last->next;
    n->next = head;    /* new node points to old head */
    last->next = n;    /* last node now points to new node */
    head = n;          /* head is updated */
}

/* Traverse — must stop when we reach head again */
void traverse() {
    if (head == NULL) { printf("Empty\n"); return; }
    struct CircularNode* temp = head;
    printf("Circular: ");
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);  /* stop when back at head */
    printf("(back to head)\n");
}

int main() {
    insert_at_beginning(30);
    insert_at_beginning(20);
    insert_at_beginning(10);
    traverse();
    return 0;
}