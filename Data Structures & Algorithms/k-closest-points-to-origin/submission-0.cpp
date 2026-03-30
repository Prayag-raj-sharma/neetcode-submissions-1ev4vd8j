class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<double, vector<int>> >pq;
        vector<vector<int>> ans;

        for(auto p: points) {
            double dis = p[0] * p[0] + p[1] * p[1];
            pq.push({dis, p});

            if(pq.size() > k) {
                pq.pop();
            }
        }
        while(!pq.empty()) {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};
