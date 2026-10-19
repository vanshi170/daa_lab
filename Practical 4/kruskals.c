#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void kruskalMST(int **cost, int V)
{
    int parent[V];

    // Initialize each vertex as its own parent
    for (int i = 0; i < V; i++)
        parent[i] = i;

    int edges = 0;
    int totalCost = 0;

    while (edges < V - 1)
    {
        int min = 9999;
        int u = -1, v = -1;

        // Find the minimum weight edge
        // Row-wise order in upper triangular matrix
        for (int i = 0; i < V; i++)
        {
            for (int j = i + 1; j < V; j++)
            {
                if (cost[i][j] < min)
                {
                    min = cost[i][j];
                    u = i;
                    v = j;
                }
            }
        }

        // Find root of u
        int rootU = u;
        while (parent[rootU] != rootU)
            rootU = parent[rootU];

        // Find root of v
        int rootV = v;
        while (parent[rootV] != rootV)
            rootV = parent[rootV];

        // If they belong to different sets, include the edge
        if (rootU != rootV)
        {
            edges++;
            totalCost += min;

            printf("Edge %d:(%d, %d) cost:%d\n",
                   edges - 1, u, v, min);

            parent[rootV] = rootU;
        }

        // Remove this edge from consideration
        cost[u][v] = 9999;
    }

    printf("Minimum cost= %d\n", totalCost);
}


int main() {
    int V;
    printf("No of vertices: ");
    scanf("%d", &V);

    int **cost = (int **)malloc(V * sizeof(int *));
    for (int i = 0; i < V; i++)
        cost[i] = (int *)malloc(V * sizeof(int));

    printf("Adjacency matrix:\n");
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            scanf("%d", &cost[i][j]);

    kruskalMST(cost, V);

    for (int i = 0; i < V; i++)
        free(cost[i]);
    free(cost);

    return 0;
}