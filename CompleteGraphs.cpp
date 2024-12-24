#include <iostream>
using namespace std;

class Graph {
    int** adjMatrix; // Adjacency matrix to represent the graph
    int n;           // Number of vertices

public:
    // Constructor to initialize the graph
    Graph(int vertices) {
        n = vertices;

        // Dynamically allocate memory for the adjacency matrix
        adjMatrix = new int*[n];
        for (int i = 0; i < n; i++) {
            adjMatrix[i] = new int[n];
            for (int j = 0; j < n; j++) {
                adjMatrix[i][j] = 0; // Initialize all edges as 0 (no edge)
            }
        }
    }

    // Function to add an edge
    void addEdge(int u, int v, bool bi = false) {
        adjMatrix[u][v] = 1; // Set edge from u to v
        if (bi) {
            adjMatrix[v][u] = 1; // Set edge from v to u for bi-directional
        }
    }

    // Function to delete an edge
    void deleteEdge(int u, int v, bool bi = false) {
        adjMatrix[u][v] = 0; // Remove edge from u to v
        if (bi) {
            adjMatrix[v][u] = 0; // Remove edge from v to u for bi-directional
        }
    }

    // Function to insert a new vertex
    void insertVertex() {
        int** newMatrix = new int*[n + 1]; // Create a new matrix with one more vertex
        for (int i = 0; i <= n; i++) {
            newMatrix[i] = new int[n + 1];
            for (int j = 0; j <= n; j++) {
                if (i < n && j < n) {
                    newMatrix[i][j] = adjMatrix[i][j]; // Copy old values
                } else {
                    newMatrix[i][j] = 0; // Initialize new edges as 0
                }
            }
        }

        // Free old adjacency matrix
        for (int i = 0; i < n; i++) {
            delete[] adjMatrix[i];
        }
        delete[] adjMatrix;

        adjMatrix = newMatrix; // Update adjacency matrix to new one
        n++; // Increase the number of vertices
    }

    // Function to delete a vertex
    void deleteVertex(int vertex) {
        int** newMatrix = new int*[n - 1]; // Create a new matrix with one less vertex
        for (int i = 0, newI = 0; i < n; i++) {
            if (i == vertex) continue; // Skip the vertex to be deleted
            newMatrix[newI] = new int[n - 1];
            for (int j = 0, newJ = 0; j < n; j++) {
                if (j == vertex) continue; // Skip the vertex to be deleted
                newMatrix[newI][newJ] = adjMatrix[i][j];
                newJ++;
            }
            newI++;
        }

        // Free old adjacency matrix
        for (int i = 0; i < n; i++) {
            delete[] adjMatrix[i];
        }
        delete[] adjMatrix;

        adjMatrix = newMatrix; // Update adjacency matrix to new one
        n--; // Decrease the number of vertices
    }

    // BFS function (iterative)
    void BFS(int start) {
        bool* visited = new bool[n];
        for (int i = 0; i < n; i++) {
            visited[i] = false;
        }

        // Create a simple queue for BFS
        int* queue = new int[n];
        int front = 0, rear = 0;

        visited[start] = true;
        queue[rear++] = start;

        cout << "BFS starting from vertex " << start << ": ";

        while (front < rear) {
            int vertex = queue[front++]; // Dequeue
            cout << vertex << " ";

            for (int i = 0; i < n; i++) {
                if (adjMatrix[vertex][i] == 1 && !visited[i]) {
                    visited[i] = true;
                    queue[rear++] = i; // Enqueue
                }
            }
        }
        cout << endl;

        delete[] visited;
        delete[] queue;
    }

    // DFS function (recursive)
    void DFS(int vertex, bool visited[]) {
        visited[vertex] = true;
        cout << vertex << " "; // Output the visited node

        for (int i = 0; i < n; i++) {
            if (adjMatrix[vertex][i] == 1 && !visited[i]) {
                DFS(i, visited); // Recurse into the adjacent vertex
            }
        }
    }

    // Function to initiate DFS
    void printDFS(int start) {
        bool* visited = new bool[n];
        for (int i = 0; i < n; i++) {
            visited[i] = false;
        }

        cout << "DFS starting from vertex " << start << ": ";
        DFS(start, visited); // Start DFS from the given vertex
        cout << endl;

        delete[] visited;
    }

    // Function to print the graph
    void printGraph() {
        for (int i = 0; i < n; i++) {
            cout << i << " -> ";
            for (int j = 0; j < n; j++) {
                if (adjMatrix[i][j] == 1) {
                    cout << j << " ";
                }
            }
            cout << endl;
        }
    }

    // Cycle detection for undirected graph
    bool cycleDetectionUndirected(int v, bool visited[], int parent) {
        visited[v] = true;

        for (int i = 0; i < n; i++) {
            if (adjMatrix[v][i] == 1) {
                if (!visited[i]) {
                    if (cycleDetectionUndirected(i, visited, v))
                        return true;
                } else if (i != parent) { // If visited and not the parent, cycle found
                    return true;
                }
            }
        }

        return false;
    }

    // Function to check for cycles in an undirected graph
    bool hasCycleUndirected() {
        bool* visited = new bool[n];
        for (int i = 0; i < n; i++) {
            visited[i] = false;
        }

        // Check for cycles in every component
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                if (cycleDetectionUndirected(i, visited, -1)) {
                    delete[] visited;
                    return true;
                }
            }
        }

        delete[] visited;
        return false;
    }

    // Cycle detection for directed graph
    bool cycleDetectionDirected(int v, bool visited[], bool recursionStack[]) {
        if (recursionStack[v]) return true; // Cycle found

        if (visited[v]) return false;

        visited[v] = true;
        recursionStack[v] = true;

        for (int i = 0; i < n; i++) {
            if (adjMatrix[v][i] == 1) {
                if (cycleDetectionDirected(i, visited, recursionStack)) {
                    return true;
                }
            }
        }

        recursionStack[v] = false;
        return false;
    }

    // Function to check for cycles in a directed graph
    bool hasCycleDirected() {
        bool* visited = new bool[n];
        bool* recursionStack = new bool[n];
        for (int i = 0; i < n; i++) {
            visited[i] = false;
            recursionStack[i] = false;
        }

        // Check for cycles in each vertex
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                if (cycleDetectionDirected(i, visited, recursionStack)) {
                    delete[] visited;
                    delete[] recursionStack;
                    return true;
                }
            }
        }

        delete[] visited;
        delete[] recursionStack;
        return false;
    }

    // Destructor to free memory
    ~Graph() {
        for (int i = 0; i < n; i++) {
            delete[] adjMatrix[i];
        }
        delete[] adjMatrix;
    }
};

int main() {
    Graph g(4); // Initialize graph with 4 vertices

    // Add edges to the graph
    g.addEdge(0, 1);
    g.addEdge(0, 2, true); // Bi-directional edge
    g.addEdge(1, 2);
    g.addEdge(2, 3);

    // Print initial graph
    cout << "Initial Graph:" << endl;
    g.printGraph();

    // Perform BFS from vertex 0
    g.BFS(0);

    // Perform DFS from vertex 0
    g.printDFS(0);

    // Add a new vertex and edge
    cout << "\nAdding a new vertex:" << endl;
    g.insertVertex();
    g.addEdge(4, 0);
    g.printGraph();

    // Delete vertex 2 and print graph
    cout << "\nDeleting vertex 2:" << endl;
    g.deleteVertex(2);
    g.printGraph();

    // Delete edge between 0 and 1 and print graph
    cout << "\nDeleting edge between 0 and 1:" << endl;
    g.deleteEdge(0, 1);
    g.printGraph();
 
    // Check for cycles in undirected graph
    cout << "\nCycle detection in undirected graph: " << (g.hasCycleUndirected() ? "Cycle detected!" : "No cycle.") << endl;

    // Check for cycles in directed graph
    cout << "Cycle detection in directed graph: " << (g.hasCycleDirected() ? "Cycle detected!" : "No cycle.") << endl;

    return 0;}
