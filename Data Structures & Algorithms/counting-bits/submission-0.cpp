class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> dp(n + 1, 0);
        int offset = 1;
        for(int i = 1; i <= n; i++) {
            dp[i] = 1 + dp[i - offset];
            if(i + 1 == offset * 2) {
                offset <<= 1;
            }
        }
        return dp; 
    }
};
