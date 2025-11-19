
bool isBipartite(int V, vector<int>adj[]){
    
    vector<int> visColor (V,-1);
    for (int i=0; i<V; ++i) {
        if (color[i] == -1) {
            if (!dfs(i, 0, visColor, adj)) return false;
        }
    }
    return true;
}

void dfs(int node, int color, vector<int> &visColor, vectorvector<int> &adj) {
    visColor[node] = color;

    for (neigh: adj[node]) {
        if (visColor[neigh] ==-1) {
            if (!dfs(neigh, !color, visColor, adj)) return false;
        } esle if (visColor[neigh] == color) return false;
    }
    return true;
}