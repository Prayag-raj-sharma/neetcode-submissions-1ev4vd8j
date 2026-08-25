class Solution {
private:
    int solve(int index, string& s, vector<int>& dp) {
        if(index == s.size()) return 1;

        if(s[index] == '0') {
            return 0;
        }

        if(dp[index] != -1) {
            return dp[index];
        }

        // one digit
        int ways = solve(index + 1, s, dp);

        // two digit
        if(index + 1 < s.size() && 
        (s[index] == '1' || (s[index] == '2' && s[index + 1] <= '6'))){
            ways += solve(index + 2, s, dp);
        }

        return dp[index] = ways;

    }
public:
    int numDecodings(string s) {
        int n = s.size();
        vector<int> dp(n + 1, -1);
        return solve(0, s, dp);  
    }
};