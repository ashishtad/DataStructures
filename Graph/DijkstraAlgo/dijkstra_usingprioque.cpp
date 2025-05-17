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
        std::priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push(make_pair(0, src));
        vector<int> dist(V, 1e9);
        dist[src] = 0;
        
        while(!pq.empty()) {
            auto [edgewt, node] = pq.top();
            pq.pop();
            for(auto [neigh, wt]: adjList[node]) {
                if(edgewt+wt < dist[neigh]) {
                    dist[neigh] = edgewt+wt;
                    pq.push(make_pair(dist[neigh],neigh));
                }
            }
            
        }
        return dist;
    }
};
