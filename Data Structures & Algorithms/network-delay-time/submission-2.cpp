class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> adj(n + 1);
        priority_queue<pair<int, int>, vector<pair<int, int>>,
        greater<pair<int, int>>> pq;
        vector<int> dist(n + 1, 1e9);
        dist[k] = 0;

        int time = 0;

        for(auto time: times) {
            int u = time[0];
            int v = time[1];
            int t = time[2];

            adj[u].push_back({v, t});
        }

        pq.push({0, k});

        while(!pq.empty()) {
            auto [currTime, node] = pq.top();
            pq.pop(); 

            if(currTime > dist[node]) continue;

            for(auto [nbrNode, edgeTime]: adj[node]) {
                int newTime = currTime + edgeTime;

                if(newTime < dist[nbrNode]) {
                    dist[nbrNode] = newTime;
                    pq.push({newTime, nbrNode});
                }
            }
        }

        for(int i = 1; i <= n; i++) {
            if(dist[i] == 1e9) return -1;

            time = max(time, dist[i]);
        }
        return time;
    }
};
