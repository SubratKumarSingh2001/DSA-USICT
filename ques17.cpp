#include <iostream>
#include <cstdlib>
#include <climits>
#include <algorithm>
using namespace std;

struct Edge {
    int src, dest, weight;
};

struct Graph {
    int numVertices, numEdges;
    Edge* edges;
    int** adjMatrix;
};

// Function to create a graph with given vertices and edges
Graph* createGraph(int vertices, int edges) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->numVertices = vertices;
    graph->numEdges = edges;

    // Allocate memory for edges
    graph->edges = (Edge*)malloc(edges * sizeof(Edge));

    // Initialize adjacency matrix for Dijkstra's algorithm
    graph->adjMatrix = (int**)malloc(vertices * sizeof(int*));
    for (int i = 0; i < vertices; i++) {
        graph->adjMatrix[i] = (int*)malloc(vertices * sizeof(int));
        for (int j = 0; j < vertices; j++)
            graph->adjMatrix[i][j] = (i == j) ? 0 : INT_MAX;
    }
    return graph;
}

// Add an edge to the graph
void addEdge(Graph* graph, int src, int dest, int weight) {
    graph->edges[graph->numEdges++] = {src, dest, weight};
    graph->adjMatrix[src][dest] = weight;
    graph->adjMatrix[dest][src] = weight;  // For undirected graph
}

// Utility function to find the vertex with the minimum distance
int minDistance(int* dist, bool* visited, int vertices) {
    int min = INT_MAX, minIndex = -1;
    for (int v = 0; v < vertices; v++) {
        if (!visited[v] && dist[v] <= min) {
            min = dist[v];
            minIndex = v;
        }
    }
    return minIndex;
}

// Dijkstra's algorithm
void dijkstra(Graph* graph, int startVertex) {
    int vertices = graph->numVertices;
    int* dist = (int*)malloc(vertices * sizeof(int));
    bool* visited = (bool*)malloc(vertices * sizeof(bool));

    for (int i = 0; i < vertices; i++) {
        dist[i] = INT_MAX;
        visited[i] = false;
    }
    dist[startVertex] = 0;

    for (int i = 0; i < vertices - 1; i++) {
        int u = minDistance(dist, visited, vertices);
        visited[u] = true;

        for (int v = 0; v < vertices; v++) {
            if (!visited[v] && graph->adjMatrix[u][v] != INT_MAX && dist[u] != INT_MAX &&
                dist[u] + graph->adjMatrix[u][v] < dist[v]) {
                dist[v] = dist[u] + graph->adjMatrix[u][v];
            }
        }
    }

    cout << "Vertex\tDistance from Source " << startVertex << endl;
    for (int i = 0; i < vertices; i++) {
        cout << i << "\t" << dist[i] << endl;
    }

    free(dist);
    free(visited);
}

// Union-Find structures for Kruskal's algorithm
struct Subset {
    int parent;
    int rank;
};

// Find function for union-find (with path compression)
int find(Subset subsets[], int i) {
    if (subsets[i].parent != i)
        subsets[i].parent = find(subsets, subsets[i].parent);
    return subsets[i].parent;
}

// Union function for union-find (with union by rank)
void Union(Subset subsets[], int x, int y) {
    int rootX = find(subsets, x);
    int rootY = find(subsets, y);

    if (subsets[rootX].rank < subsets[rootY].rank)
        subsets[rootX].parent = rootY;
    else if (subsets[rootX].rank > subsets[rootY].rank)
        subsets[rootY].parent = rootX;
    else {
        subsets[rootY].parent = rootX;
        subsets[rootX].rank++;
    }
}

// Comparison function to sort edges by weight
int compareEdges(const void* a, const void* b) {
    Edge* edgeA = (Edge*)a;
    Edge* edgeB = (Edge*)b;
    return edgeA->weight - edgeB->weight;
}

// Kruskal's algorithm for Minimum Spanning Tree
void kruskalMST(Graph* graph) {
    int vertices = graph->numVertices;
    Edge* result = (Edge*)malloc((vertices - 1) * sizeof(Edge));
    int e = 0;
    qsort(graph->edges, graph->numEdges, sizeof(graph->edges[0]), compareEdges);

    Subset* subsets = (Subset*)malloc(vertices * sizeof(Subset));
    for (int v = 0; v < vertices; v++) {
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }

    int i = 0;
    while (e < vertices - 1 && i < graph->numEdges) {
        Edge nextEdge = graph->edges[i++];
        int x = find(subsets, nextEdge.src);
        int y = find(subsets, nextEdge.dest);

        if (x != y) {
            result[e++] = nextEdge;
            Union(subsets, x, y);
        }
    }

    cout << "Edges in the Minimum Spanning Tree:\n";
    for (i = 0; i < e; i++)
        cout << result[i].src << " -- " << result[i].dest << " == " << result[i].weight << endl;

    free(result);
    free(subsets);
}

// Free allocated memory for the graph
void freeGraph(Graph* graph) {
    free(graph->edges);
    for (int i = 0; i < graph->numVertices; i++)
        free(graph->adjMatrix[i]);
    free(graph->adjMatrix);
    free(graph);
}

int main() {
    int vertices, edges, src, dest, weight, choice, startVertex;

    cout << "Enter the number of vertices: ";
    cin >> vertices;
    cout << "Enter the number of edges: ";
    cin >> edges;

    Graph* graph = createGraph(vertices, edges);
    cout << "Enter each edge (src dest weight):\n";
    for (int i = 0; i < edges; i++) {
        cin >> src >> dest >> weight;
        addEdge(graph, src, dest, weight);
    }

    do {
        cout << "\nMenu:\n";
        cout << "1. Dijkstra's Shortest Path\n";
        cout << "2. Kruskal's Minimum Spanning Tree\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter the starting vertex for Dijkstra's algorithm: ";
                cin >> startVertex;
                dijkstra(graph, startVertex);
                break;

            case 2:
                kruskalMST(graph);
                break;

            case 3:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 3);

    freeGraph(graph);
    return 0;
}
