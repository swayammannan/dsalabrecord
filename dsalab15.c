#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

struct AdjNode { int vertex; struct AdjNode* next; };
struct AdjNode* adj[MAX];
int V;

void initNetwork(int n){
    V=n; for(int i=0;i<V;i++) adj[i]=NULL;
}

/* Add friendship (undirected edge) */
void add_friendship(int u,int v){
    struct AdjNode* n=(struct AdjNode*)malloc(sizeof(struct AdjNode));
    n->vertex=v;n->next=adj[u];adj[u]=n;
    struct AdjNode* m=(struct AdjNode*)malloc(sizeof(struct AdjNode));
    m->vertex=u;m->next=adj[v];adj[v]=m;
}

/* BFS to find shortest path (degrees of separation) */
int degrees_of_separation(int user1, int user2) {
    int visited[MAX], dist[MAX];
    memset(visited, 0, sizeof(visited));
    memset(dist, -1, sizeof(dist));

    /* Simple BFS queue using array */
    int queue[MAX], front=0, rear=0;

    visited[user1] = 1;
    dist[user1] = 0;
    queue[rear++] = user1;

    while (front < rear) {
        int curr = queue[front++];  /* dequeue */
        struct AdjNode* t = adj[curr];
        while (t != NULL) {
            if (!visited[t->vertex]) {
                visited[t->vertex] = 1;
                dist[t->vertex] = dist[curr] + 1;  /* one more edge */
                queue[rear++] = t->vertex;
                if (t->vertex == user2)
                    return dist[t->vertex];  /* found! */
            }
            t = t->next;
        }
    }
    return -1;  /* not connected */
}

int main() {
    initNetwork(6);
    add_friendship(0,1);
    add_friendship(1,2);
    add_friendship(2,3);
    add_friendship(3,4);
    add_friendship(0,5);
    add_friendship(5,4);

    int d = degrees_of_separation(0, 4);
    printf("Degrees of separation between 0 and 4: %d\n", d);
    return 0;
}