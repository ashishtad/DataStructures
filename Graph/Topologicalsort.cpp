#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Graph {
private:
    int V;
    vector<vector<int>> adjacency_list;

public:
    Graph(int vertices) {
        V = vertices;
        adjacency_list.resize(V);
    }

    ~Graph() {}

    void addEdge(int u, int v) {
        adjacency_list[u].push_back(v);
    }

    vector<int> topologicalSort() {
        vector<int> vertices_indegree(V, 0);
        
        // Calculate indegrees of all vertices
        for (int i = 0; i < V; ++i) {
            for (int neighbor : adjacency_list[i]) {
                vertices_indegree[neighbor]++;
            }
        }

        queue<int> gq;
        // Push all vertices with 0 indegree
        for (int i = 0; i < V; ++i) {
            if (vertices_indegree[i] == 0)
                gq.push(i);
        }

        vector<int> result;
        while (!gq.empty()) {
            int front = gq.front();
            gq.pop();
            result.push_back(front);

            for (int neighbor : adjacency_list[front]) {
                --vertices_indegree[neighbor]; // Reduce indegree
                if (vertices_indegree[neighbor] == 0)
                    gq.push(neighbor);
            }
        }

        // Cycle detection
        if (result.size() != V) {
            cout << "Graph contains a cycle\n";
            return {};
        }

        return result;
    }

    void printTopologicalSort() {
        vector<int> res = topologicalSort();
        
        if (res.empty()) {
            cout << "Topological sorting is not possible (cycle detected)\n";
            return;
        }

        for (int v : res)
            cout << v << " --> ";
        cout << "NULL\n";
    }
};

int main() {
    Graph g(6);
    g.addEdge(5, 2);
    g.addEdge(5, 0);
    g.addEdge(4, 0);
    g.addEdge(4, 1);
    g.addEdge(2, 3);
    g.addEdge(3, 1);

    g.printTopologicalSort();
    return 0;
}
