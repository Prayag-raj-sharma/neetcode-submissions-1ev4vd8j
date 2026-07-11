class Solution {
private: 
    int solve(int index, vector<int>& cost) {
        if(index == 0) return cost[0]; 
        if(index == 1) return cost[1];

        return cost[index] + min(solve(index - 1, cost), 
                                 solve(index - 2, cost));

    }
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n + 1, 0);
        dp[0] = cost[0];
        dp[1] = cost[1];

        for(int i = 2; i < n; i++) {
            dp[i] = cost[i] + min(dp[i - 1], dp[i - 2]);
        }
        return min(dp[n - 1], dp[n - 2]);
    }
};
