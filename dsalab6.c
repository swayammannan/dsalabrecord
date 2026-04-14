#include <stdio.h>
#include <stdlib.h>

struct Node { int data; struct Node* next; };

struct Node* front_ptr = NULL;  /* front of queue */
struct Node* rear_ptr  = NULL;  /* back of queue  */

/* Enqueue: add to back */
void enqueue(int data) {
    struct Node* n = (struct Node*)malloc(sizeof(struct Node));
    n->data = data; n->next = NULL;
    if (rear_ptr == NULL) { front_ptr = rear_ptr = n; return; }
    rear_ptr->next = n;
    rear_ptr = n;
    printf("Enqueued %d\n", data);
}

/* Dequeue: remove from front */
int dequeue() {
    if (front_ptr == NULL) { printf("Queue empty\n"); return -1; }
    struct Node* temp = front_ptr;
    int val = temp->data;
    front_ptr = front_ptr->next;
    if (front_ptr == NULL) rear_ptr = NULL;
    free(temp);
    return val;
}

/* Front: peek at front */
int front() {
    if (front_ptr == NULL) { printf("Queue empty\n"); return -1; }
    return front_ptr->data;
}

int is_empty() { return front_ptr == NULL; }

int main() {
    enqueue(10); enqueue(20); enqueue(30);
    printf("Front: %d\n", front());
    printf("Dequeue: %d\n", dequeue());
    printf("Front now: %d\n", front());
    printf("Empty? %s\n", is_empty() ? "Yes" : "No");
    return 0;
}