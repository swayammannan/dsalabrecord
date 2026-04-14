#include <stdio.h>
#include <stdlib.h>
#define MAX 100

/* Linked list node for adjacency list */
struct AdjNode { int vertex; struct AdjNode* next; };
struct AdjNode* adj[MAX];  /* adj[v] = head of list for vertex v */
int V;  /* number of vertices */

void initGraph(int vertices) {
    V = vertices;
    for(int i=0;i<V;i++) adj[i]=NULL;
}

/* Add undirected edge between v and w */
void add_edge(int v, int w) {
    /* Add w to v's list */
    struct AdjNode* n1 = (struct AdjNode*)malloc(sizeof(struct AdjNode));
    n1->vertex=w; n1->next=adj[v]; adj[v]=n1;
    /* Add v to w's list (undirected) */
    struct AdjNode* n2 = (struct AdjNode*)malloc(sizeof(struct AdjNode));
    n2->vertex=v; n2->next=adj[w]; adj[w]=n2;
}

void printGraph() {
    for(int i=0;i<V;i++){
        printf("Vertex %d: ",i);
        struct AdjNode* t=adj[i];
        while(t){printf("%d ",t->vertex);t=t->next;}
        printf("\n");
    }
}

int main() {
    initGraph(5);
    add_edge(0,1); add_edge(0,4);
    add_edge(1,2); add_edge(1,3);
    add_edge(2,3);
    printGraph();
    return 0;
}