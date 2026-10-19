#include <stdio.h>
#include <limits.h>

#define INF 100000000

struct Edge {
    int u, v, weight;
};

int main() {
    int V, E;

    scanf("%d", &V);
    scanf("%d", &E);

    struct Edge edges[E];

    for (int i = 0; i < E; i++) {
        scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].weight);
    }

    int source;
    scanf("%d", &source);

    int dist[V + 1];
    int parent[V + 1];

    // Initialize distances and parents
    for (int i = 1; i <= V; i++) {
        dist[i] = INF;
        parent[i] = -1;
    }

    dist[source] = 0;

    // Bellman-Ford: Relax all edges V-1 times
    for (int i = 1; i <= V - 1; i++) {
        int updated = 0;

        for (int j = 0; j < E; j++) {
            int u = edges[j].u;
            int v = edges[j].v;
            int w = edges[j].weight;

            if (dist[u] != INF && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                parent[v] = u;
                updated = 1;
            }
        }

        // If no distance was updated, we can stop early
        if (!updated)
            break;
    }

    // Check for negative weight cycle
    for (int i = 0; i < E; i++) {
        int u = edges[i].u;
        int v = edges[i].v;
        int w = edges[i].weight;

        if (dist[u] != INF && dist[u] + w < dist[v]) {
            printf("Negative cycle detected\n");
            return 0;
        }
    }

    // Print shortest distance and path for every vertex except source
    for (int v = 1; v <= V; v++) {
        if (v == source)
            continue;

        if (dist[v] == INF) {
            printf("%d INF None\n", v);
        } else {
            // Store path in reverse
            int path[V + 1];
            int count = 0;
            int current = v;

            while (current != -1) {
                path[count++] = current;
                current = parent[current];
            }

            printf("%d %d ", v, dist[v]);

            // Print path from source to destination
            for (int i = count - 1; i >= 0; i--) {
                printf("%d", path[i]);

                if (i != 0)
                    printf("->");
            }

            printf("\n");
        }
    }

    return 0;
}