class Solution {
private:
    vector<int> topoSort(int V, vector<vector<int>>& adj) {
        vector<int> indegree(V, 0);
        vector<int> topo;
        queue<int> q;


        for(int i = 0; i < V; i++) {
            for(auto it: adj[i]) {
                indegree[it]++;
            }
        }

        for(int i = 0; i < V; i++) {
            if(indegree[i] == 0) {
                q.push(i);
            }
        }

        while(!q.empty()) {
            int node = q.front();
            topo.push_back(node);
            q.pop();

            for(auto nbr: adj[node]) {
                indegree[nbr]--;
                if(indegree[nbr] == 0) {
                    q.push(nbr);
                }
            }
        }

        return topo;
    }
public:
    string foreignDictionary(vector<string>& words) {
        int n = words.size();
        vector<vector<int>> adj(26);
        vector<vector<bool>> edge(26, vector<bool>(26, false));
        vector<bool> present(26, false);

        for(auto w: words) {
            for(char c: w) {
                present[c - 'a'] = true;
            }
        }

        for(int i = 0; i < n - 1; i++) {
            string s1 = words[i];
            string s2 = words[i + 1];

             // Invalid: prefix comes after longer word
            if (s1.size() > s2.size() && 
                s1.substr(0, s2.size()) == s2) {
                return "";
            }

            int len = min(s1.size(), s2.size());

            for(int ptr = 0; ptr < len; ptr++) {

                if(s1[ptr] != s2[ptr]) {
                    int u = s1[ptr] - 'a';
                    int v = s2[ptr] - 'a';
                    if (!edge[u][v]) {  // prevent duplicate
                        edge[u][v] = true;
                        adj[u].push_back(v);
                    }
                    break;
                }
            }
        }

        // Count total letters present
        int totalLetters = 0;
        for (int i = 0; i < 26; i++) {
            if (present[i]) totalLetters++;
        }

        vector<int> topo = topoSort(26, adj);
        vector<bool> seen(26, false);
        string ans = "";

         for (int c : topo) {
            if (present[c]) {
                seen[c] = true;
                ans.push_back('a' + c);
            }
        }
        
        // If cycle exists, some letters missing
        for (int i = 0; i < 26; i++) {
            if (present[i] && !seen[i]) {
                return "";
            }
        }
        return ans;
    }
};
