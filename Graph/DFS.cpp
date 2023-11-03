/**
 * Algorithm:
1. Create a recursive function that takes the index of node and a visited array.
2. Mark the current node as visited and print the node.
3. Traverse all the adjacent and unmarked nodes and call the recursive function with index of adjacent node.
 * 
*/
// Time Complexity: O(V + E)
// Space Complexity: O(V)

#include<bits/stdc++.h>
#include<vector>
#include "iostream"

using namespace std;

void DFSUtil( int v, vector<int> adjacentMat[],
              bool visited[], vector<int> & result) {


                if(visited[v]) 
                    return;

                result.push_back(v);
                visited[v] = true;

                for( int node: adjacentMat[v]) {
                    if(!visited[node])
                        DFSUtil(node,adjacentMat,visited,result);
                }
              }

vector<int> DFSGraph( int V, vector<int> adjacentMat [] ) {
    
    bool visited[V];
    memset(visited,false,sizeof(visited));

    vector<int> result;

    for( int i=0; i<V; ++i) {
        if( !visited[i])
            DFSUtil(i,adjacentMat,visited,result);
    }
    return result;
}