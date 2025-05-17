#include <iostream>
using namespace std;

const int INF = 999999; // Used as infinity

// Function to find the vertex with minimum key value
int minKey(int key[], bool mstSet[], int V) {
    int min = INF, minIndex;

    for (int v = 0; v < V; v++) {
        if (!mstSet[v] && key[v] < min) {
            min = key[v];
            minIndex = v;
        }
    }
    return minIndex;
}

// Function to print the constructed MST
void printMST(int parent[], int graph[100][100], int V) {
    cout << "\nEdge \tWeight\n";
    for (int i = 1; i < V; i++)
        cout << parent[i] << " - " << i << "\t" << graph[i][parent[i]] << endl;
}

// Prim's algorithm
void primMST(int graph[100][100], int V) {
    int parent[100];   // Stores MST
    int key[100];      // Used to pick minimum weight edge
    bool mstSet[100];  // Keeps track of included vertices

    // Initialize all keys as infinite
    for (int i = 0; i < V; i++) {
        key[i] = INF;
        mstSet[i] = false;
    }

    key[0] = 0;       // Start from vertex 0
    parent[0] = -1;   // First node is always root of MST

    for (int count = 0; count < V - 1; count++) {
        int u = minKey(key, mstSet, V);
        mstSet[u] = true;

        for (int v = 0; v < V; v++) {
            if (graph[u][v] && !mstSet[v] && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    printMST(parent, graph, V);
}

int main() {
    int V;
    int graph[100][100];

    cout << "Enter number of vertices: ";
    cin >> V;

    cout << "Enter adjacency matrix (0 if no edge):\n";
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            cin >> graph[i][j];

    primMST(graph, V);

    return 0;
}
