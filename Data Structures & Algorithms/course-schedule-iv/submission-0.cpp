class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        int n = numCourses;
        vector<vector<int>> adj(n);
        queue<int> q;
        vector<int> topo;
        vector<int> inDegree(n, 0);

        vector<vector<bool>> isPre(n, vector<bool>(n, false));

        for(auto pre: prerequisites) {
            int u = pre[0];
            int v = pre[1];

            adj[u].push_back(v);
        }

        for(int i = 0; i < n; i++) {
            for(auto x: adj[i]) {
                inDegree[x]++;
            }
        }

        for(int i = 0; i < n; i++) {
            if(inDegree[i] == 0) {
                q.push(i);
            }
        }

        while(!q.empty()) {
            int node = q.front();
            q.pop();
            topo.push_back(node);

            for(auto nbr: adj[node]) {

                isPre[nbr][node] = true;

                for(int i = 0; i < n; i++) {
                    if(isPre[node][i]) {
                        isPre[nbr][i] = true;
                    }
                }

                inDegree[nbr]--;
                if(inDegree[nbr] == 0) {
                    q.push(nbr);
                }
            }
        }

        vector<bool> ans;

        for(auto& query: queries) {
            int u = query[0];
            int v = query[1];

            ans.push_back(isPre[v][u]);
        }
        return ans; 
    }
};