class Solution {
private:
    int solve(int i, int j, string s, string t, vector<vector<int>>& dp) {
        if(j < 0) return 1;
        if(i < 0) return 0;

        if(dp[i][j] != -1) return dp[i][j];
        
        int result = 0;
        if(s[i] == t[j]) {
            int both = solve(i - 1, j - 1, s, t, dp);
            int stay = solve(i - 1, j, s, t, dp);
            result = both + stay;
        } else {
            result = solve(i - 1, j, s, t, dp);
        }
        return dp[i][j] = result;
    }
public:
    int numDistinct(string s, string t) {
        int n = s.length();
        int m = t.length();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return solve(n - 1, m - 1, s, t, dp);
    }
};
