
/**
 * Find if Path Exists in Graph
 * There is a bi-directional graph with n vertices, where each vertex is labeled from 0 to n - 1 (inclusive). The edges in the graph are represented as a 2D integer array edges, 
 * where each edges[i] = [ui, vi] denotes a bi-directional edge between vertex ui and vertex vi. Every vertex pair is connected by at most one edge, and no vertex has an edge to itself.

*  You want to determine if there is a valid path that exists from vertex source to vertex destination.

*  Given edges and the integers n, source, and destination, return true if there is a valid path from source to destination, or false otherwise.
*  Approach:
*  1. Create an adjacency list from the edges given
*  2. Perform DFS/BFS to search if a path exists from start -> end or vice a versa.
*/

#include "iostream"
#include<vector>
#include<stack>
using namespace std;

class Solution {

public:

    /* Adjacency list represnetation*/
    vector<vector<int>> adjList;

    /* create the adjacency list. */
    void addEdge( int from_edge, int to_edge) {
        /* Bidirectional edge*/
        adjList[from_edge].push_back(to_edge);
        adjList[to_edge].push_back(from_edge);
    }

    bool findInDFS( int start , int end) {
        if( start == end ) {
            return true;
        }
        vector<bool> visited(adjList.size(),false);
        stack<int> st;
        st.push(start);

        while( !st.empty() ) {
            int start_vertex = st.top();
            st.pop();
            visited[start_vertex] = true;

            for ( auto end_vertex: adjList[start_vertex]) {
                if( end_vertex == end)
                    return true;
                else {
                    
                    if( !visited[end_vertex])
                        st.push(end_vertex);
                }
            }
        }
        return false;

    }
    
    bool validPath(int n, vector<vector<int>>& edges, int start, int end) {
        if( edges.empty())
            return true;
        
        adjList.reserve(n);
        for ( int i=0; i< edges.size(); ++i) {
             addEdge(edges[i][0],edges[i][1]);
        }
       
        return findInDFS(start,end);

    }

};