/*
 * This is Dijkstra Algorithm implementation using queue.
 * This is less efficient as using queue , there is possibility
 * of traversing the longer or unecessariy path before actually
 * traversing the shorter path.
 * Hence using priority is correct and the most effective.
*/

#include "iostream"
#include <vector>
#include <queue>
#include <stdio.h>

using namespace std;
typedef pair<int,int> pi;
void dijkstra(const vector<vector<pi>> &graph,
              int src, vector<int> &dist ) {

    queue<int> q;
    /* Push the source node to q and dist to reach src is 0 */
    q.push(src);
    dist[src] = 0;

    while( !q.empty() ) {

        int u = q.front();
        q.pop();
        /*
          Traverse the neighbour nodes.
          Push the neighbour node to queue only if,
          the already existing shortest path to that node
          is greater than the cur node shortest path+ the weight to reach the neighbour.
          That means new shortest path found to reach the neighbour node.
        */
        for( auto neighbour_node : graph[u]){
            if( dist[neighbour_node.first] > (dist[u] + neighbour_node.second) ){
                q.push(neighbour_node.first);
                dist[neighbour_node.first] = dist[u]+neighbour_node.second;
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