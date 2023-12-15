#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

// Structure to represent a graph edge and its weight
struct Edge {
    int destination;
    int weight;

    Edge(int dest, int w) : destination(dest), weight(w) {}
};

// Structure to represent a vertex and its distance from the source
struct Vertex {
    int id;
    int distance;

    Vertex(int i, int d) : id(i), distance(d) {}

    // Priority queue requires a comparison operator
    bool operator>(const Vertex& other) const {
        return distance > other.distance;
    }
};

// Graph class with Dijkstra's algorithm implementation
class Graph {
private:
    int vertices;
    vector<vector<Edge>> adjacencyList;

public:
    Graph(int v) : vertices(v), adjacencyList(v) {}

    // Add an edge to the graph
    void addEdge(int source, int destination, int weight) {
        adjacencyList[source].emplace_back(destination, weight);
        adjacencyList[destination].emplace_back(source, weight); // For undirected graph
    }

    // Dijkstra's algorithm to find the shortest paths from a source vertex
    void dijkstra(int source) {
        vector<int> distance(vertices, numeric_limits<int>::max());
        priority_queue<Vertex, vector<Vertex>, greater<Vertex>> pq;

        distance[source] = 0;
        pq.push(Vertex(source, 0));

        while (!pq.empty()) {
            Vertex current = pq.top();
            pq.pop();

            for (const Edge& edge : adjacencyList[current.id]) {
                int newDistance = current.distance + edge.weight;

                if (newDistance < distance[edge.destination]) {
                    distance[edge.destination] = newDistance;
                    pq.push(Vertex(edge.destination, newDistance));
                }
            }
        }

        // Displaying the shortest distances
        cout << "Shortest Distances from Source " << source << ":\n";
        for (int i = 0; i < vertices; ++i) {
            cout << "To vertex " << i << ": " << distance[i] << "\n";
        }
    }
};

// Main function
int main() {
    // Creating a graph with 5 vertices
    Graph graph(5);

    // Adding edges with weights
    graph.addEdge(0, 1, 2);
    graph.addEdge(0, 2, 4);
    graph.addEdge(1, 2, 1);
    graph.addEdge(1, 3, 7);
    graph.addEdge(2, 4, 3);
    graph.addEdge(3, 4, 1);

    // Running Dijkstra's algorithm from source vertex 0
    graph.dijkstra(0);

    return 0;
}