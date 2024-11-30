#include <iostream>
#include <queue>
#include <stack>
#include <cstdlib>
using namespace std;

struct Node {
    int vertex;
    Node* next;
};

struct Graph {
    int numVertices;
    Node** adjLists;
    bool* visited;
};

// Function to create a new node
Node* createNode(int v) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = v;
    newNode->next = nullptr;
    return newNode;
}

// Function to create a graph with `numVertices` vertices
Graph* createGraph(int vertices) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->numVertices = vertices;

    // Create an array of adjacency lists. Size of array will be `vertices`
    graph->adjLists = (Node**)malloc(vertices * sizeof(Node*));
    graph->visited = (bool*)malloc(vertices * sizeof(bool));

    // Initialize each adjacency list as empty and set all vertices as not visited
    for (int i = 0; i < vertices; i++) {
        graph->adjLists[i] = nullptr;
        graph->visited[i] = false;
    }
    return graph;
}

// Function to add an edge to an undirected graph
void addEdge(Graph* graph, int src, int dest) {
    // Add edge from src to dest
    Node* newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;

    // Since graph is undirected, add edge from dest to src also
    newNode = createNode(src);
    newNode->next = graph->adjLists[dest];
    graph->adjLists[dest] = newNode;
}

// DFS algorithm
void DFS(Graph* graph, int vertex) {
    stack<int> stack;
    for (int i = 0; i < graph->numVertices; i++) 
        graph->visited[i] = false;

    stack.push(vertex);

    while (!stack.empty()) {
        int current = stack.top();
        stack.pop();

        if (!graph->visited[current]) {
            cout << current << " ";
            graph->visited[current] = true;
        }

        Node* temp = graph->adjLists[current];
        while (temp) {
            int adjVertex = temp->vertex;
            if (!graph->visited[adjVertex])
                stack.push(adjVertex);
            temp = temp->next;
        }
    }
    cout << endl;
}

// BFS algorithm
void BFS(Graph* graph, int startVertex) {
    queue<int> q;
    for (int i = 0; i < graph->numVertices; i++)
        graph->visited[i] = false;

    graph->visited[startVertex] = true;
    q.push(startVertex);

    while (!q.empty()) {
        int current = q.front();
        cout << current << " ";
        q.pop();

        Node* temp = graph->adjLists[current];
        while (temp) {
            int adjVertex = temp->vertex;
            if (!graph->visited[adjVertex]) {
                graph->visited[adjVertex] = true;
                q.push(adjVertex);
            }
            temp = temp->next;
        }
    }
    cout << endl;
}

// Free memory allocated for the graph
void freeGraph(Graph* graph) {
    for (int i = 0; i < graph->numVertices; i++) {
        Node* temp = graph->adjLists[i];
        while (temp) {
            Node* toDelete = temp;
            temp = temp->next;
            free(toDelete);
        }
    }
    free(graph->adjLists);
    free(graph->visited);
    free(graph);
}

int main() {
    int vertices, choice, src, dest, startVertex;
    
    cout << "Enter the number of vertices: ";
    cin >> vertices;

    Graph* graph = createGraph(vertices);

    do {
        cout << "\nGraph Menu:\n";
        cout << "1. Add edge\n";
        cout << "2. DFS traversal\n";
        cout << "3. BFS traversal\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter source and destination vertex (0 to " << vertices - 1 << "): ";
                cin >> src >> dest;
                addEdge(graph, src, dest);
                cout << "Edge added between " << src << " and " << dest << ".\n";
                break;

            case 2:
                cout << "Enter starting vertex for DFS: ";
                cin >> startVertex;
                cout << "DFS traversal starting from vertex " << startVertex << ": ";
                DFS(graph, startVertex);
                break;

            case 3:
                cout << "Enter starting vertex for BFS: ";
                cin >> startVertex;
                cout << "BFS traversal starting from vertex " << startVertex << ": ";
                BFS(graph, startVertex);
                break;

            case 4:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 4);

    // Free the allocated memory
    freeGraph(graph);

    return 0;
}
