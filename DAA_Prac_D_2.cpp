#include <iostream>
#include <vector>
using namespace std;

class Graph {
public:
    int vertices;
    vector<vector<int>> adjList;

    // Constructor
    Graph(int vertices) {
        this->vertices = vertices;
        adjList.resize(vertices);
    }

    // Function to add an edge
    void addEdge(int u, int v) {
        adjList[u].push_back(v);
    }

    // Recursive function to count paths
    int countPaths(int start, int end) {
        if (start == end) {
            return 1; // Base case: path found
        }
        int pathCount = 0;
        for (int neighbor : adjList[start]) {
            pathCount += countPaths(neighbor, end);
        }
        return pathCount;
    }
};

int main() {
    // Create a graph with 5 vertices (A=0, B=1, C=2, D=3, E=4)
    Graph g(5);
    
    // Adding edges as per the graph in the image
    g.addEdge(0, 1); // A -> B
    g.addEdge(0, 2); // A -> C
    g.addEdge(0, 3); // A -> D
    g.addEdge(1, 4); // B -> E
    g.addEdge(2, 4); // C -> E
    g.addEdge(3, 2); // D -> C
    g.addEdge(3, 4); // D -> E

    // Counting paths between A and E (0 to 4)
    cout << "Total paths between A and E are " << g.countPaths(0, 4) << endl;

    // Counting paths between A and C (0 to 2)
    cout << "Total paths between A and C are " << g.countPaths(0, 2) << endl;

    return 0;
}
