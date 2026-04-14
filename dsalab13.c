#include <stdio.h>
#include <stdlib.h>
#define MAX 100

struct AdjNode { int vertex; struct AdjNode* next; };
struct AdjNode* adj[MAX];
int visited[MAX];
int V;

void initGraph(int v){
    V=v;
    for(int i=0;i<V;i++){adj[i]=NULL;visited[i]=0;}
}
void add_edge(int v,int w){
    struct AdjNode* n=(struct AdjNode*)malloc(sizeof(struct AdjNode));
    n->vertex=w;n->next=adj[v];adj[v]=n;
    struct AdjNode* m=(struct AdjNode*)malloc(sizeof(struct AdjNode));
    m->vertex=v;m->next=adj[w];adj[w]=m;
}

/* Recursive DFS */
void dfs(int start) {
    visited[start] = 1;
    printf("%d ", start);  /* print current vertex */
    struct AdjNode* t = adj[start];
    while (t != NULL) {
        if (!visited[t->vertex])  /* visit unvisited neighbor */
            dfs(t->vertex);
        t = t->next;
    }
}

int main() {
    initGraph(5);
    add_edge(0,1); add_edge(0,2);
    add_edge(1,3); add_edge(2,4);
    printf("DFS from vertex 0: ");
    dfs(0);
    printf("\n");
    return 0;
}