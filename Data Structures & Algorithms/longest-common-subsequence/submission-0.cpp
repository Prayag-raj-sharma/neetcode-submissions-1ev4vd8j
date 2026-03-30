class Solution {
private:
    int lcs(int i, int j, string& t1, string& t2, 
            vector<vector<int>>& dp) {
        if(i < 0 || j < 0) {
            return 0;
        }

        if(dp[i][j] != -1) return dp[i][j];
        
        if(t1[i] == t2[j]) {
            return dp[i][j] = 1 + lcs(i - 1, j - 1, t1, t2, dp);
        } else {
            return dp[i][j] = max(lcs(i - 1, j, t1, t2, dp),
             lcs(i, j - 1, t1, t2, dp));
        }
    }
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
        return lcs(n - 1, m - 1, text1, text2, dp);
    }
};
