

#include"iostream"
#include<vector>

using namespace std;

class Graph
{
private:
    //Represents the vertices in graph
    int vertices; 
    vector<vector<int>> adjacency_list; 

public:
    Graph() : vertices(0) {}
    Graph( std::vector<std::vector<int> >::size_type v) : vertices(v),adjacency_list(v){ }
    
    ~Graph(){}

    void addEdge( int u, int v) {

        adjacency_list[u].push_back(v);
        adjacency_list[v].push_back(u); // For directed graph this would be commented
    }

    void printGraph() {
        for( int i =0; i< vertices; ++i){
            cout<<"Adjacent node of vertex "<<i<<":";
            for( auto node: adjacency_list[i]){
                cout<<node<<"-->";
            }
            cout<<"\n";
        }
    }

    void deleteEdge( int u , int v) {

        for( auto it = adjacency_list[u].begin(); it!= adjacency_list[u].end(); ++it ){
            if( *it == v)
                adjacency_list[u].erase(it);
        }

          for( auto it = adjacency_list[v].begin(); it!= adjacency_list[v].end(); ++it ){
            if( *it == u)
                adjacency_list[v].erase(it);
        }
    }
};

int main() {

    Graph g(5);
    g.addEdge(1,2);
    g.addEdge(0,3);
    g.addEdge(1, 3);
    g.addEdge(2, 4);
    g.addEdge(4, 0);

    g.deleteEdge(2,4);
    g.printGraph();
    return 0;
}


