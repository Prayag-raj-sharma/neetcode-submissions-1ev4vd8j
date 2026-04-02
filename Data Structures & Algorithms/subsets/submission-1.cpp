class Solution {
private:
    void solve(int index, vector<int>& nums, vector<int>& ans, 
               vector<vector<int>>& result) {
        if(index < 0) {
            result.push_back(ans);
            return;
        }

        ans.push_back(nums[index]);
        solve(index - 1, nums, ans, result);
        ans.pop_back();

        solve(index - 1, nums, ans, result);
        
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> result;
        vector<int> ans;
        solve(n - 1, nums, ans, result);
        return result; 
    }
};
