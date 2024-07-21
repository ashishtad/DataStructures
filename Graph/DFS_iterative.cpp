#include "iostream"
#include<stack>
#include<vector>

using namespace std;

vector<int> DFS( int source, vector<vector<int>> adjList, int vertices){

    vector<bool>visited(vertices,false);
    vector<int> result;
    std::stack<int> st;
    st.push(source);
    visited[source]=true;

    while(!st.empty()){
        int top = st.top();
        st.pop();
        result.push_back(top);

        for( int neighbour : adjList[top]){
            if(!visited[neighbour]){
                st.push(neighbour);
                visited[neighbour]= true;
            }
        }
    }

}