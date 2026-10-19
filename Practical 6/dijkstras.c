#include <limits.h> 
#include <stdio.h>
#define MAX 20
int V, E;
int graph[MAX][MAX];
#define INFINITY 99999

void dijkstra(int G[MAX][MAX], int n, int startnode) {
	int distance[MAX];
	int visited[MAX];
	int parent[MAX];
	int i, j, count, min, next;

	for (i = 1; i <= n; i++)
	{
		distance[i] = INFINITY;
		visited[i] = 0;
		parent[i] = -1;
	}

	distance[startnode] = 0;
	for (count = 1; count <= n; count++)
	{
		min = INFINITY;
		next = -1;
		for (i = 1; i <= n; i++)
		{
			if (!visited[i] && distance[i] < min)
			{
				min = distance[i];
				next = i;
			}
		}
		if (next == -1)
			break;

		visited[next] = 1;
		for (j = 1; j <= n; j++)
		{
			if (!visited[j] && G[next][j] != 0)
			{
				if (distance[next] + G[next][j] < distance[j])
				{
					distance[j] = distance[next] + G[next][j];
					parent[j] = next;
				}
			}
		}
	}

	printf("Node\tDistance\tPath\n");
	for (i = 1; i <= n; i++)
	{
		if (i == startnode)
			continue;
		printf("%4d\t", i);

		if (distance[i] == INFINITY)
		{
			printf("     INF\tNO PATH\n");
		}
		else
		{
			printf("%8d\t", distance[i]);
			int path[MAX];
			int k = 0;
			int current = i;

			while (current != -1)
			{
				path[k] = current;
				k++;
				current = parent[current];
			}

			for (j = 0; j < k; j++)
			{
				printf("%d", path[j]);
				if (j < k - 1)
					printf("<-");
			}
			printf("\n");
		}
	}
}
int main() { 
	int s, d, w, i, j;
	printf("Enter the number of vertices : ");
	scanf("%d", &V);
	printf("Enter the number of edges : ");
	scanf("%d", &E);
	for(i = 1 ; i <= V; i++) {
		for(j = 1; j <= V; j++) {
			graph[i][i] = 0;
		}
	}
	for(i = 1; i <= E; i++) {
		printf("Enter source : ");
		scanf("%d", &s);
		printf("Enter destination : ");
		scanf("%d", &d);
		printf("Enter weight : ");
		scanf("%d", &w);
		if(s > V || d > V || s <= 0 || d <= 0) {
			printf("Invalid index. Try again.\n");
			i--;
			continue;
		} else {
			graph[s][d] = w;
		}
	}
	printf("Enter the source :");
	scanf("%d", &s);
	dijkstra(graph, V, s); 
	return 0; 
} 