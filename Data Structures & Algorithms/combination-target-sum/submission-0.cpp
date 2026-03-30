class Solution {
private: 
    void solve(int index, vector<int>& nums, vector<int>& ans,
               vector<vector<int>>& result, int target) {
        if(target == 0) {
            result.push_back(ans);
            return;
        }

        if(target < 0) return;

        for(int i = index; i < nums.size(); i++) {
            ans.push_back(nums[i]);

            solve(i, nums, ans, result, target - nums[i]);

            ans.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> result;
        vector<int> ans;
        solve(0, nums, ans, result, target);
        return result;  
    }
};
