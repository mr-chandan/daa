// 13. Find the **Shortest Paths** to other verƟces using **Dijkstra’s Algorithm** from a given vertex in a weighted connected graph. 
#include <stdio.h>

int minof(int distance[], int visited[], int numVertices)
{
    int minDistance = 999;
    int min = -1;
    for (int v = 0; v < numVertices; v++)
    {
        if (!visited[v] && distance[v] <= minDistance)
        {
            minDistance = distance[v];
            min = v;
        }
    }
    return min;
}

void dijkstra(int graph[15][15], int startVertex, int numVertices)
{
    int distance[10];
    int visited[10];

    for (int i = 0; i < numVertices; i++)
    {
        distance[i] = 999;
        visited[i] = 0;
    }

    distance[startVertex] = 0;

    for (int count = 0; count < numVertices; count++)
    {
        int j;

        int min = minof(distance, visited, numVertices);

        visited[min] = 1;

        for (j = 0; j < numVertices; j++)
        {
            if (graph[min][j] != 0 && visited[j] == 0 &&
                distance[min] != 999)
            {
                int newdistance = distance[min] + graph[min][j];
                if (newdistance < distance[j])
                {
                    distance[j] = newdistance;
                }
            }
        }
    }

    printf("Vertex\tDistance from Start\n");
    for (int i = 0; i < numVertices; i++)
    {
        printf("%d\t%d\n", i, distance[i]);
    }
}

void main()
{
    int graph[15][15];
    int numVertices;
    int startVertex;

    printf("Enter the number of vertices: ");
    scanf("%d", &numVertices);

    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < numVertices; i++)
    {
        for (int j = 0; j < numVertices; j++)
        {
            scanf("%d", &graph[i][j]);
        }
    }

    printf("Enter the starting vertex: ");
    scanf("%d", &startVertex);

    dijkstra(graph, startVertex, numVertices);

}