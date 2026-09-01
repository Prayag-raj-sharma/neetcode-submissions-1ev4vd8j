class Solution {
private:
    void dfs(int node, vector<bool>& visited, vector<vector<int>>& adj) {
        visited[node] = true;

        for(auto nbr: adj[node]) {
            if(!visited[nbr])
             dfs(nbr, visited, adj);
        }
    }
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);

        for(auto& edge: edges) {
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<bool> visited(n, false);
        int components = 0;

        for(int i = 0; i < n; i++) {
            if(visited[i]) {
                continue;
            }

            components++;
            dfs(i, visited, adj);
        }
        return components;
    }
};
