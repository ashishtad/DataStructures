/*
    Given a Undirected Graph of N vertices from 0 to N-1 and M edges and a 2D Integer array edges, 
    where there is a edge from vertex edges[i][0] to vertex edges[i][1] of unit weight.

    Find the shortest path from the source to all other nodes in this graph. In this problem statement, 
    we have assumed the source vertex to be ‘0’. If a vertex is unreachable from the source node, then return -1 for that vertex.
*/
#include <vector>
#include <queue>
#include <climits>

using namespace std;
class Solution {
  public:
    vector<int> shortestPath(vector<vector<int>>& edges, int N,int M){

        vector<vector<int>> adjlist(N);
        for(auto edge : edges) {
            adjlist[edge[0]].push_back(edge[1]);
            adjlist[edge[1]].push_back(edge[0]);
        }
        queue<int> q;
        q.push(0);
        vector<int> dist(N, INT_MAX);
        /* Distance of node-0 to itself is 0 */
        dist[0] = 0; 

        while(!q.empty()) {
            int node = q.front();
            q.pop();
            for( int &neigh: adjlist[node] ) {

                if(dist[node]+1 < dist[neigh]) {
                    dist[neigh] = dist[node]+1;
                    q.push(neigh);
                }
        }
        vector<int> res(N, -1);
        for(int i=0; i<N; ++i) {
            if(dist[i] != INT_MAX) res[i] = dist[i];
        }
        return res;
    }
};
