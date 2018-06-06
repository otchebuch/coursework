#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

typedef struct Edge
{
    int src, dest, weight;
};

typedef struct Graph
{
    int vertex, edges;
    struct Edge *edge;
};

struct Graph *initGraph(int vertex, int edges)
{
   struct Graph *graph = (struct Graph*) malloc( sizeof(struct Graph));
    graph->vertex = vertex;
    graph->edges = edges;
    graph->edge = (struct Edge*) malloc( graph->edges * sizeof( struct Edge ) );
    return graph;
}

void print(int distan[], int n)
{
    printf("\nVertex\tFrom src\n");
    int i;

    for (i = 0; i < n; ++i){
        printf("%d \t\t %d\n", i, distan[i]);
    }
}

void fordBellman(struct Graph *graph, int src)
{
    int vertex = graph->vertex;

    int edges = graph->edges;

    int storingDistance[vertex];

    int i,j;

    for (i = 0; i < vertex; i++)
        storingDistance[i] = INT_MAX;

    storingDistance[src] = 0;

    for (i = 1; i <= vertex-1; i++)
    {
        for (j = 0; j < edges; j++)
        {
            int k = graph->edge[j].src;

            int z = graph->edge[j].dest;

            int weight = graph->edge[j].weight;

            if (storingDistance[k] + weight < storingDistance[z])
                storingDistance[z] = storingDistance[k] + weight;
        }
    }

    for (i = 0; i < edges; i++)
    {
        int k = graph->edge[i].src;

        int z = graph->edge[i].dest;

        int weight = graph->edge[i].weight;

        if (storingDistance[k] + weight < storingDistance[z])
            printf("There's a negative cycle in the graph\n");
    }

    print(storingDistance, vertex);

    return;
}
int main() {
 return 0;
}
