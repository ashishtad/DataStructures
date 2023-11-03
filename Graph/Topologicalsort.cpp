
#include "iostream"
#include<vector>
#include<queue>

using namespace std;

class  Graph
{
private:
    /* data */
    int V;
    vector<vector<int>> adjacency_list;
public:
     Graph(/* args */);
    ~ Graph();

    vector<int> topologicalSort() {

        vector<int> vertices_indegree(V,0);
        //calculate the indegree of each vertex
        for( int i=0; i<V; ++i) {
            for( auto neighbour_vertex: adjacency_list[i] )
                vertices_indegree[neighbour_vertex]++;
        }

        queue<int> gq;
        //Get the vertices with 0 indegress in a queue
        for( auto v: vertices_indegree) {
            if( v ==0 )
                gq.push(v);
        }
        //Still if queue is empty then start from any node
        if( gq.empty())
            gq.push(0); //Here starting with 0
        
        vector<int> result;

        while( !gq.empty()) {
            int front = gq.front();
            gq.pop();

            result.push_back(front);

            for( auto it : adjacency_list[front]) {
                //Decrement the neighbour vertx indegree as the starting vertex i.e front is processed.
                --vertices_indegree[it];
                if( 0 == vertices_indegree[it])
                    gq.push(it);
            }

        }
        return result;

    }

    void printTopologicalSort() {
        vector<int> res = topologicalSort();

        if( res.size() != V)
            cout<<"Graph contains a cycle\n";
            
        for( auto it: res)
            cout<<it<<"-->";

        cout<<"NULL";
    }
};

 