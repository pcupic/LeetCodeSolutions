#include <stdio.h>
#include <stdlib.h>

typedef struct graph {
    int** adj;     
    int vertexNum; 
} Graph;

void freeGraph(Graph* g) {
    if (g) {
        for (int i = 0; i < g->vertexNum; i++) {
            free(g->adj[i]);
        }
        free(g->adj);
        free(g);
    }
}

Graph* createGraph(int vertexNum) {
    Graph* g = (Graph*)malloc(sizeof(Graph));
    if (g == NULL) {
        perror("Graph memory allocation error");
        exit(1);
    }
    
    g->vertexNum = vertexNum;
    g->adj = (int**)calloc(g->vertexNum, sizeof(int*));
    if (g->adj == NULL) {
        perror("Adjacency matrix memory allocation error");
        free(g);
        exit(1);
    }
    
    for (int i = 0; i < g->vertexNum; i++) {
        g->adj[i] = (int*)calloc(g->vertexNum, sizeof(int));
        if (g->adj[i] == NULL) {
            perror("Failed to allocate memory for adjacency matrix row");
            for (int j = 0; j < i; j++) {
                free(g->adj[j]);
            }
            free(g->adj);
            free(g);
            exit(1);
        }
    }
    
    return g;
}

void addEdge(Graph* g, int i, int j) {
    if (i >= 0 && i < g->vertexNum && j >= 0 && j < g->vertexNum) {
        g->adj[i][j] = 1;
        g->adj[j][i] = 1; 
	}
}

void print_adjacency_matrix(Graph* g) {
    printf("Adjacency Matrix:\n");
    for (int i = 0; i < g->vertexNum; i++) {
        for (int j = 0; j < g->vertexNum; j++) {
            printf("%d ", g->adj[i][j]);
        }
        printf("\n");
    }
}

int main(void) {
	
    Graph* graph = createGraph(5);

    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 3, 4);

    print_adjacency_matrix(graph);

    freeGraph(graph);

    return 0;
}
