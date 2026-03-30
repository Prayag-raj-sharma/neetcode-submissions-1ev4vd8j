class Solution {
private:
    int solve(int n, vector<int>& dp) {
        if(n == 1) return 1;
        if(n == 2) return 2;
        if(dp[n] != -1) return dp[n];

        return dp[n] = solve(n - 1, dp) + solve(n - 2, dp); 
    }
public:
    int climbStairs(int n) {
        // vector<int> dp(n + 1, -1);
        // dp[0] = dp[1] = 1;
        // dp[2] = 2;
        int curr = 0;
        int prev2 = 1, prev = 1;
        for(int i = 2; i <= n; i++) {
            curr = prev + prev2;
            prev2 = prev;
            prev = curr;
        }
        return prev;
    }
};
