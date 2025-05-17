/*
    Why set is used?

    In Dijkstra, you may need to update the distance of a node if you find a shorter path.

std::priority_queue doesn't allow you to remove or update a specific element easily — so it may keep multiple outdated entries in the heap.

std::set (usually std::set<pair<int, int>>) maintains the elements in sorted order and allows erasure in O(log n).

The set stores (distance, node).

Before inserting an updated (new_dist, node) pair, erase the old one (if it exists).

This avoids having stale (outdated) distances in the data structure.

*/


// User Function Template
class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        // Code here
        /* Create adj list */
        vector<vector<pair<int,int>>> adjList(V);
        for(auto edge: edges) {
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];
            adjList[u].emplace_back(v,w);
            adjList[v].emplace_back(u,w);
        }
        set<pair<int, int>> s;
        s.insert(make_pair(0,src));
        vector<int> dist(V, 1e9);
        dist[src] = 0;
        
        while(!s.empty()) {
            auto [edgewt, node] = s.begin();
            s.erase(s.begin());

            for(auto [neigh, wt]: adjList[node]) {
                if(edgewt+wt < dist[neigh]) {
                    if(dist[neigh] != 1e9) s.erase(dist[neigh], neigh);
                    dist[neigh] = edgewt+wt;
                    s.insert(make_pair(dist[neigh],neigh));
                }
            }
            
        }
        return dist;
    }
};