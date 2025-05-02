
/*
    Given a Directed Graph with V vertices (Numbered from 0 to V-1) and E edges, check whether it contains any cycle or not.
The graph is represented as a 2D vector edges[][], where each entry edges[i] = [u, v] denotes an edge from verticex u to v.

Reference: https://www.youtube.com/watch?v=9twcmtQj4DU&ab_channel=takeUforward
*/

class Solution {
  private:
  bool dfs(int node, vector<int> &visited, vector<int> &vispath, const vector<vector<int>> &adjList) {
      visited[node] = 1;
      vispath[node] = 1;
      for(int neigh : adjList[node]) {
          if(!visited[neigh]) {
              if (dfs(neigh, visited, vispath, adjList)) return true;
          /* If visited already and vispath is set to 1,
             that means this node is in current path and already vsisited which is cycle */
          } else if(vispath[neigh]) return true;
      }
      /* Reset the node vispath to 0 as we are returning back fom this node */
      vispath[node] = 0;
      return false;
  }
  public:
    bool isCyclic(int V, vector<vector<int>> &edges) {
        // code here
        vector<vector<int>> adjList(V);
        for(auto &edge: edges) {
            adjList[edge[0]].push_back(edge[1]);
        }
        
        vector<int> visited(V, 0);
        /* This keeps track of the current visited path.
           If any node is in cur visisted path and it's already visisted then cycle exists.
        */
        vector<int> vispath(V,0);
        
        for(int node=0; node<V; ++node) {
            if(!visited[node]) {
                if(dfs(node, visited, vispath, adjList)) return true;
            }
        }
        return false;
    }
};
