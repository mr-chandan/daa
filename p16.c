#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int dest;
    struct Node *next;
};

struct AdjList
{
    struct Node *head;
};

struct Node *createNode(int dest)
{
    struct Node *newNode =
        (struct Node *)malloc(sizeof(struct Node));
    newNode->dest = dest;
    newNode->next = NULL;
    return newNode;
}

void DFSRec(struct AdjList adj[], int visited[], int s)
{

    visited[s] = 1;

    printf("%d ", s);

    struct Node *current = adj[s].head;
    while (current != NULL)
    {
        int dest = current->dest;
        if (!visited[dest])
        {
            DFSRec(adj, visited, dest);
        }
        current = current->next;
    }
}

void DFS(struct AdjList adj[], int V, int s)
{
    int visited[5] = {0};
    DFSRec(adj, visited, s);
}

void addEdge(struct AdjList adj[], int s, int t)
{
    struct Node *newNode = createNode(t);
    newNode->next = adj[s].head;
    adj[s].head = newNode;

    newNode = createNode(s);
    newNode->next = adj[t].head;
    adj[t].head = newNode;
}

int main()
{
    int V = 5;

    struct AdjList adj[V];

    for (int i = 0; i < V; i++)
    {
        adj[i].head = NULL;
    }

    int E = 5;

    int edges[][2] = {{1, 2}, {1, 0}, {2, 0}, {2, 3}, {2, 4}};

    for (int i = 0; i < E; i++)
    {
        addEdge(adj, edges[i][0], edges[i][1]);
    }

    int source = 1;
    printf("DFS from source: %d\n", source);
    DFS(adj, V, source);

    return 0;
}