class Solution {
private:
    int find(int node, vector<int>& parent) {
        if(parent[node] != node) {
            parent[node] = find(parent[node], parent);
        }
        return parent[node];
    }
    bool unionSet(int u, int v, vector<int>& parent, vector<int>& rank) {
        int pu = find(u, parent);
        int pv = find(v, parent);

        if(pu == pv) return false;

        if(rank[pu] < rank[pv]) {
            parent[pu] = pv;
        } else if(rank[pu] > rank[pv]) {
            parent[pv] = pu;
        } else {
            parent[pv] = pu;
            rank[pu]++;
        }
        return true;
    }
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> parent(n + 1);
        vector<int> rank(n + 1, 0);

        for(int i = 1; i <= n; i++) {
            parent[i] = i;
        }

        for(auto& edge: edges) {
            if(!unionSet(edge[0], edge[1], parent, rank)) {
                return edge;
            }
        }
        return {};   
    }
};
