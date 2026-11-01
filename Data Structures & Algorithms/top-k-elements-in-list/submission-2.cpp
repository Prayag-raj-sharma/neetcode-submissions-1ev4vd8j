class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> mp;
        priority_queue<pair<int, int>> pq;
        vector<int> ans;

        for(int i = 0; i < n; i++) {
            mp[nums[i]]++;
        }

        for(auto m: mp) {
            pq.push({m.second, m.first});
        }

        while (k--) {
                ans.push_back(pq.top().second);
                pq.pop();
        }
        return ans;  
    }
};
