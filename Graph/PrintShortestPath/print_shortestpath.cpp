/*
  Given a undirected weight graph,
  Find the shortest weight path between the vertex 1 and the vertex n.
  Input are the n nodes and m edges
  If path does not exists then return list of -1.

  Approach
  ========

  We will be using dijkstra algorithm here.
  We need to remember the nodes from which we are coming from while calculating the shortest path.
  Along with regular data structures used in dijkstra which are set/priority queue and dist array, we need to have another parent array
  which basically denotes from where each node is coming from i.e parent of each node. 
*/

#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
       
        /* Form the adjacency list */
        vector<vector<pair<int,int>>> adjList(n+1);
        for(auto edge: edges) {
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];
            adjList[u].push_back(make_pair(v,w));
            adjList[v].push_back(make_pair(u,w));
        }
        vector<int> dist(n+1, 1e9);
        dist[1] = 0;
        /* Set to store shorter (dist,nodes)*/
        set<pair<int,int>> st;
        /* Push vertex 1 with dist 0 as it is the source. */
        st.insert(make_pair(0,1));
        vector<int> parent(n+1);
        for(int i=1; i<=n; ++i) parent[i] = i;

        while(!st.empty()) {
            auto [edgewt, node] = *(st.begin());
            st.erase(st.begin());
            for(auto neigh:adjList[node]) {
                auto [neighNode, neighwt] = neigh;
                if(edgewt+neighwt < dist[neighNode]) {
                    /* If the neighbour is already visited and has a older shorter distance , erase from set */
                    if(dist[neighNode] != 1e9) st.erase(make_pair(dist[neighNode], neighNode));
                    dist[neighNode] = edgewt+neighwt;
                    /* Update the the parent node */
                    parent[neighNode] = node;
                }
            }
        }
        /* If the nth node is not reachable after dijkstra then return -1 list*/
        if(dist[n] == 1e9) return {-1};
        vector<int> path;
        int node = n;
        /* Get the nodes path stores in parent list which would be in reverse order */
        path.push_back(node);
        while(node != parent[node]) {
            path.push_back(parent[node]);
            node = parent[node];
        }
        path.push_back(1);
        std::reverse(path.begin(), path.end());
        return path;

    }
};
