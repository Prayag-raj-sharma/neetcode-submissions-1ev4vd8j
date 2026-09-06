class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        using State = pair<double, int>;
        vector<vector<State>> adj(n);
        
        priority_queue<State> pq;
        vector<double> maxP(n, 0.0);
        maxP[start_node] = 1.0;

        for(int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            double prob = succProb[i];

            adj[u].push_back({prob, v});
            adj[v].push_back({prob, u});
        }

        pq.push({1.0, start_node});

        while(!pq.empty()) {
            auto [prob, node] = pq.top();
            pq.pop();

            if(prob < maxP[node]) continue;

            if(node == end_node) {
                return prob;
            }

            for(auto [edgeProb, nbr]: adj[node]) {
                double newProb = prob * edgeProb;

                if(newProb > maxP[nbr]) {
                    maxP[nbr] = newProb;
                    pq.push({newProb, nbr});
                }
            }
        }
        return 0.0;
    }
};