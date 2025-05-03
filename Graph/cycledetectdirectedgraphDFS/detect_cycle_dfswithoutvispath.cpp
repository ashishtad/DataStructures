/*
  This solution is to detect cycle in directed graph using only a single visited array.
  Here there is no use of visitedpath array.
  visited array
  0 : unvisited
  1 : visited
  2 : current visited path 
*/

class Solution {
  private:
  bool dfs(int node, vector<int> &visited, const vector<vector<int>> &adjList) {
      /* mark this node as current visited path */
      visited[node] = 2;

      for(int neigh : adjList[node]) {
          if(visited[neigh] ==0) {
              if (dfs(neigh, visited, adjList)) return true;
          /* If the neigh node is in current visited path then it's a cycle */
          } else if(visited[neigh] == 2) return true;        
      }
      /* Reset back the node as visited as we are leaving the node from cur visited path */
      visited[node] = 1;
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
        for(int node=0; node<V; ++node) {
            if(visited[node]==0) {
                if(dfs(node, visited, adjList)) return true;
            }
        }
        return false;
    }
};