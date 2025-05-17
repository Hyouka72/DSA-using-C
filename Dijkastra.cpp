#include <iostream>
#include <vector>
using namespace std;

const int INF = 999999; // Representing "infinity"

// Function to find the vertex with the minimum distance value
int minDistance(const vector<int>& dist, const vector<bool>& visited, int V) {
    int min = INF, minIndex = -1;
    for (int v = 0; v < V; v++) {
        if (!visited[v] && dist[v] <= min) {
            min = dist[v];
            minIndex = v;
        }
    }
    return minIndex;
}

// Dijkstra’s algorithm
void dijkstra(const vector<vector<int>>& graph, int src) {
    int V = graph.size();
    vector<int> dist(V, INF);
    vector<bool> visited(V, false);

    dist[src] = 0;

    for (int count = 0; count < V - 1; count++) {
        int u = minDistance(dist, visited, V);
        if (u == -1) break; // No reachable vertex left
        visited[u] = true;

        for (int v = 0; v < V; v++) {
            if (!visited[v] && graph[u][v] && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    // Output the result
    cout << "\nVertex\tDistance from Source (" << src << ")\n";
    for (int i = 0; i < V; i++) {
        if (dist[i] == INF)
            cout << i << "\t" << "INF" << "\n";
        else
            cout << i << "\t" << dist[i] << "\n";
    }
}

int main() {
    int V;
    cout << "Enter number of vertices: ";
    cin >> V;

    vector<vector<int>> graph(V, vector<int>(V));

    cout << "Enter the adjacency matrix (0 if no edge):\n";
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            cin >> graph[i][j];

    int src;
    cout << "Enter source vertex (0 to " << V - 1 << "): ";
    cin >> src;

    dijkstra(graph, src);
    
    return 0;
}
