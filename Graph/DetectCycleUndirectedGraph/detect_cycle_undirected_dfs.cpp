
class Solution{
public:
    bool isCycle(int V, vector<int> adj[]) {
        
        vector<bool> visited (V, false);

        for (int i=0; i< V; ++i) {
            if (!visited[i]) {
                if dfs(i, -1, visited, adj) return true;
            }
        }
        return false;
    }

    bool dfs(int node, int parent, vector<bool> &visited,  vector<int> adj[]) {
        visited[node] = true;

        for (const int neigh: adj[node]) {
            if (!visited[neigh]) {
                if (dfs(neigh, node, visited, adj)) return true;
            } else if (neigh != parent) return true;
        }
        return false;
    }
};