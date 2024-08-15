/*
 * Dijkstra implementation using priority queue.
*/

#include "iostream"
#include <vector>
#include <queue>
#include <stdio.h>

using namespace std;
typedef pair<int,int> pi;
void dijkstra(const vector<vector<pi>> &graph,
              int src, vector<int> &dist ) {

   /* Prio queue to hold elements in min heap manner.*/
   std::priority_queue<pi, vector<pi>, greater<pi>> pq;
   pq.push({0,src});
   dist[src] = 0;    

   while( !pq.empty() ){

        int u = pq.top().second;
        int u_dist = pq.top().first;
        pq.pop();
        /* Skip if the node distance is greater than the shotest known path
            in dist[].   
        */
        if( u_dist > dist[u]) continue;
        /* Traverse the neighbour nodes of u */
        for( auto neigh_node: graph[u]) {
            /* Found a shorter distance. Update the dist*/
            if( dist[neigh_node.first] > (dist[u]+neigh_node.second) ){
                dist[neigh_node.first] = dist[u]+neigh_node.second;
                pq.push({(dist[u]+neigh_node.second),neigh_node.first});
            }
        }
   }

}

int main(){

    int V=7;
    vector<vector<pi>> graph(V);
    /* Adjacency list creation */
    graph[0].push_back(make_pair(1,2));
    graph[0].push_back(make_pair(2,6));
    graph[1].push_back(make_pair(3,5));
    graph[2].push_back(make_pair(3,8));
    graph[3].push_back(make_pair(5,15));
    graph[3].push_back(make_pair(4,10));
    graph[4].push_back(make_pair(6,2));
    graph[5].push_back(make_pair(4,6));
    graph[5].push_back(make_pair(6,6));
    

    int src = 0;
    /* Vector to store least distance of each nod from src */
    vector<int> dist(V, INT16_MAX);
    dijkstra(graph, src, dist);

    cout << "Vertex Distance from Source\n";
    for (int i = 0; i < V; ++i) {
        printf("Node: %d dist:%d\n",i,dist[i]);
    }

    return 0;
}