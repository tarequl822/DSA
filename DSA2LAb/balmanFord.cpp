#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int source, destination, weight;
};

void bellmanFord(Edge graph[], int edges, int vertices, int source) {
    int distance[vertices];
    for (int i = 0; i < vertices; i++) {
        distance[i] = INT_MAX;
    }
    distance[source] = 0;

    // Relax edges (vertices - 1) times
    for (int i = 0; i < vertices - 1; i++) {
        for (int j = 0; j < edges; j++) {
            const Edge &e = graph[j];
            if (distance[e.source] != INT_MAX && distance[e.source] + e.weight < distance[e.destination]) {
                distance[e.destination] = distance[e.source] + e.weight;
            }
        }
    }

    // Check for negative weight cycles
    for (int j = 0; j < edges; j++) {
        const Edge &e = graph[j];
        if (distance[e.source] != INT_MAX && distance[e.source] + e.weight < distance[e.destination]) {
            cout << "Negative cycle detected" << endl;
            return;
        }
    }

    // Print distances
    for (int i = 0; i < vertices; i++) {
        cout << "Distance from source to vertex " << i << ": " << distance[i] << endl;
    }
}

int main() {
    const int v = 6; // Number of vertices
    const int e = 8; // Number of edges

    // Define the graph as an array of edges
    Edge graph[e] = {
        {0, 1, 5},
        {0, 2, 7},
        {1, 2, 3},
        {1, 3, 4},
        {1, 4, 6},
        {3, 4, -1},
        {3, 5, 2},
        {4, 5, -3}
    };

    bellmanFord(graph, e, v, 0);

    return 0;
}