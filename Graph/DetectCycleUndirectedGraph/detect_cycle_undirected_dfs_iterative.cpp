bool isCycle(int V, vector<int> adj[]) {
    vector<bool> visited(V, false);

    for (int start = 0; start < V; ++start) {
        if (visited[start]) continue;

        stack<pair<int,int>> st;
        st.push({start, -1});
        visited[start] = true;

        while (!st.empty()) {
            auto [node, parent] = st.top();
            st.pop();

            for (int neigh : adj[node]) {
                if (!visited[neigh]) {
                    visited[neigh] = true;
                    st.push({neigh, node});
                }
                else if (neigh != parent) {
                    return true;   // cycle detected
                }
            }
        }
    }

    return false;
}
