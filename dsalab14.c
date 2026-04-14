#include <stdio.h>
#include <stdlib.h>
#define MAX 100

struct AdjNode { int vertex; struct AdjNode* next; };
struct AdjNode* adj[MAX];
int visited[MAX];
int V;

void initGraph(int v){
    V=v; for(int i=0;i<V;i++){adj[i]=NULL;visited[i]=0;}
}
void add_edge(int v,int w){
    struct AdjNode* n=(struct AdjNode*)malloc(sizeof(struct AdjNode));
    n->vertex=w;n->next=adj[v];adj[v]=n;
    struct AdjNode* m=(struct AdjNode*)malloc(sizeof(struct AdjNode));
    m->vertex=v;m->next=adj[w];adj[w]=m;
}

/* DFS that checks for cycle. parent = node we came from */
int dfs_cycle(int v, int parent) {
    visited[v] = 1;
    struct AdjNode* t = adj[v];
    while (t != NULL) {
        if (!visited[t->vertex]) {
            if (dfs_cycle(t->vertex, v)) return 1;
        } else if (t->vertex != parent) {
            /* visited and not our parent = CYCLE! */
            return 1;
        }
        t = t->next;
    }
    return 0;
}

int detect_cycle() {
    for (int i=0;i<V;i++)
        if (!visited[i] && dfs_cycle(i,-1)) return 1;
    return 0;
}

int main() {
    initGraph(4);
    add_edge(0,1); add_edge(1,2);
    add_edge(2,3); add_edge(3,1);  /* this creates a cycle */
    printf("Cycle detected: %s\n", detect_cycle() ? "True" : "False");
    return 0;
}