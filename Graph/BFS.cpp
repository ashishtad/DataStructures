
#include <bits/stdc++.h>
#include "iostream"
#include<queue>

using namespace std;

vector<int> BFS( int vertices, vector<int> adjacentMatrix[], int source_node ) {

    vector<bool> visited(vertices,false);
    queue<int> q;
    vector<int> result;
    q.push(source_node);
    visited[source_node] = true;

    while(!q.empty()) {

        int elem = q.front();
        result.push_back(elem);
        
        q.pop();

        for( auto it : adjacentMatrix[elem]) {
            if( !visited[it]) {
                q.push(it);
                visited[it] = true;
            }
        }
    }
    return result;
}