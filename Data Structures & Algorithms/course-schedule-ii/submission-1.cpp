class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& pre) {
        int n = numCourses;
        vector<vector<int>> adj(n);
        vector<int> ans;
        vector<int> indegree(n);
        queue<int> q;

        for(auto x: pre) {
            int u = x[0];
            int v = x[1];
            adj[v].push_back(u);
        }

        for(int u = 0; u < n; u++) {
            for(auto v: adj[u]) {
                indegree[v]++;
            }
        }

        for(int i = 0; i < n; i++) {
            if(indegree[i] == 0) {
                q.push(i);
            }
        }

        while(!q.empty()) {
            int frontNode = q.front();
            q.pop();
            ans.push_back(frontNode);

            for(auto nbr: adj[frontNode]) {
                indegree[nbr]--;
                if(indegree[nbr] == 0) {
                    q.push(nbr);
                }
            }
        }
        if(ans.size() != n) return {};
        return ans;
    }
};
