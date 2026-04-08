class Solution {
private:
    int dfs(int n, int current, vector<int>& dp) {
        if(current == n) return 0;
        if(current > n) return 1e9;
        if(dp[current] != -1) return dp[current];

        int ans = 1e9;
        for(int i = 1; i * i <= n; i++) {
            int sq = i * i;
            int res = dfs(n, current + sq, dp);

            if(res != 1e9) {
                ans = min(ans, res + 1);
            }
        }
        return dp[current] = ans;
    }
public:
    int numSquares(int n) {
        vector<int> dp(n + 1, -1);
        return dfs(n, 0, dp);  
    }
};