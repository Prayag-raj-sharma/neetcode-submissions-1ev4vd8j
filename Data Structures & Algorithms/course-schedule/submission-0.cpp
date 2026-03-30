class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses;
        vector<int> adjPre[n];
        int count = 0;

        for(auto x: prerequisites) {
            int u = x[0];
            int v = x[1];
            adjPre[v].push_back(u);
        }

        vector<int> indegree(n);

        for(int u = 0; u < n; u++) {
            for(auto v: adjPre[u]) {
                indegree[v]++;
            }
        }

        queue<int> q;
        for(int i = 0; i < n; i++) {
            if(indegree[i] == 0) {
                q.push(i);
            }
        }

        while(!q.empty()) {
            int frontNode = q.front();
            q.pop();
            count++;

            for(int nbr: adjPre[frontNode]) {
                indegree[nbr]--;
                if(indegree[nbr] == 0) {
                    q.push(nbr);
                }
            }
        }
        return count == n;
    }
};
