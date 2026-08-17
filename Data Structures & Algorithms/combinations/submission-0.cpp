class Solution {
private:
    void solve(int i, int n, int k, vector<int>& ans, vector<vector<int>>& result) {
        if(ans.size() == k) {
            result.push_back(ans);
            return;
        }

        if(i > n) return;

        for(int j = i; j <= n; j++) {
            ans.push_back(j);
            solve(j + 1, n, k, ans, result);
            ans.pop_back();
        }
    }
public:
    vector<vector<int>> combine(int n, int k) {
        vector<int> ans;
        vector<vector<int>> result;
        solve(1, n, k, ans, result);
        return result;
    }
};