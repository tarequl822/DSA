#include <iostream>
#include <queue>
#include <climits>

using namespace std;

typedef pair<int, int> iPair;

class Graph {
    int V;
    int adj[100][100]; // Adjacency matrix (assumes maximum vertices = 100)

public:
    Graph(int V);
    void addEdge(int u, int v, int w);
    void dijkstra(int src);
};

Graph::Graph(int V) {
    this->V = V;
    // Initialize adjacency matrix with INT_MAX (no direct connection)
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            adj[i][j] = INT_MAX;
        }
    }
}

void Graph::addEdge(int u, int v, int w) {
    adj[u][v] = w;
    adj[v][u] = w; // For undirected graph
}

void Graph::dijkstra(int src) {
    priority_queue<iPair, vector<iPair>, greater<iPair>> pq; // Min-heap
    int dist[V];

    // Initialize distances as infinite
    for (int i = 0; i < V; i++) {
        dist[i] = INT_MAX;
    }
    dist[src] = 0;

    pq.push(make_pair(0, src));

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        // Loop through adjacent vertices of u
        for (int v = 0; v < V; v++) {
            if (adj[u][v] != INT_MAX) { // Check if there's a valid edge
                int weight = adj[u][v];
                if (dist[v] > dist[u] + weight) {
                    dist[v] = dist[u] + weight;
                    pq.push(make_pair(dist[v], v));
                }
            }
        }
    }

    cout << "Vertex Distance from Source\n";
    for (int i = 0; i < V; ++i)
        cout << i << "\t\t" << dist[i] << "\n";
}

int main() {
    int V = 9;
    Graph g(V);

    g.addEdge(0, 1, 4);
    g.addEdge(0, 7, 8);
    g.addEdge(1, 2, 8);
    g.addEdge(1, 7, 11);
    g.addEdge(2, 3, 7);
    g.addEdge(2, 8, 2);
    g.addEdge(2, 5, 4);
    g.addEdge(3, 4, 9);
    g.addEdge(3, 5, 14);
    g.addEdge(4, 5, 10);
    g.addEdge(5, 6, 2);
    g.addEdge(6, 7, 1);
    g.addEdge(6, 8, 6);
    g.addEdge(7, 8, 7);

    g.dijkstra(0);

    return 0;
}
