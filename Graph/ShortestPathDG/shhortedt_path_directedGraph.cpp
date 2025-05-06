


/*
   0: Build the adj list from the given edges.
   1. Do a toposort - DFS call to nodes and push them to stack after dfs for a node is finished.
   2. Take a dist array and make dist[src] =0
   3. Pop nodes from stack and compute the dist to neighbour nodes based on curent node distance.
*/

#include<vector>
#include<stack>
#include<climits>

using namespace std;
class Solution {
    private:
    void dfs(int node, vector<int> &visited, stack<int> &st, const vector<vector<pair<int,int>>> &adjlist) {
        visited[node] = 1;
        for(auto [v, wt]: adjlist[node]) {
            if(!visited[v]) {
                dfs(v, visited, st, adjlist);
            }
        }
        st.push(node);
    }
    public:
    vector < int > shortestPath(int N, int M, vector < vector < int >> & edges) {

        vector<vector<pair<int,int>>> adjlist(N);
        for(auto &edge: edges) {
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];
            adjlist[u].emplace_back(v, wt);
        }
        vector<int> visited(N, 0);
        stack<int> st;
        /* Do toposort */
        for( int i=0; i<N; ++i) {
            if(!visited[i]) {
                dfs(i, visited, st, adjlist);
            }
        }
        vector<int> dist(N, INT_MAX);
        /* src node is 0- to reach 0 from 0 dist =0 */
        dist[0] = 0;
        while(!st.empty()) {
            int node = st.top();
            st.pop();
            /* Continue if the node is not reachable from src yet */
            if(dist[node] == INT_MAX) continue;
            for( auto [v,wt]: adjlist[node]) {
                if(dist[node]+wt < dist[v]) {
                    dist[v] = dist[node] + wt;
                }
            }
        }
        vector<int> res(N, -1);
        for(int i=0; i<N; ++i) {
            if(dist[i]!= INT_MAX) res[i] = dist[i];
        }
        return res;
    }
};

/* Improved version using a single dist array */

class Solution {
    private:
    void dfs(int node, vector<int> &visited, stack<int> &st, const vector<vector<pair<int,int>>> &adjlist) {
        visited[node] = 1;
        for(auto [v, wt]: adjlist[node]) {
            if(!visited[v]) {
                dfs(v, visited, st, adjlist);
            }
        }
        st.push(node);
    }
    public:
    vector < int > shortestPath(int N, int M, vector < vector < int >> & edges) {

        vector<vector<pair<int,int>>> adjlist(N);
        for(auto &edge: edges) {
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];
            adjlist[u].emplace_back(v, wt);
        }
        vector<int> visited(N, 0);
        stack<int> st;
        /* Do toposort */
        for( int i=0; i<N; ++i) {
            if(!visited[i]) {
                dfs(i, visited, st, adjlist);
            }
        }
        vector<int> dist(N, -1);
        /* src node is 0- to reach 0 from 0 dist =0 */
        dist[0] = 0;
        while(!st.empty()) {
            int node = st.top();
            st.pop();
            /* Continue if the node is not reachable from src yet */
            if(dist[node] == -1) continue;
            for( auto [v,wt]: adjlist[node]) {
                if(dist[v] == -1 || dist[node]+wt < dist[v]) {
                    dist[v] = dist[node] + wt;
                }
            }
        }
  
        return dist;
    }
};