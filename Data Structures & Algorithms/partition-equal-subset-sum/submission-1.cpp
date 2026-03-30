class Solution {
private:
    bool solve(int index, vector<int>& nums, int target,
    vector<vector<bool>>& dp) {
        if(target == 0) return true;
        if(index < 0 && target != 0) return false;

        if(dp[index][target] != false) return dp[index][target];

        bool notTake = solve(index - 1, nums, target, dp);
        bool take = false;
        if(target >= nums[index]) {
            take = solve(index - 1, nums, target - nums[index], dp);
        }
        return dp[index][target] = (take || notTake);
    }
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int totalSum = 0;

        for(int i = 0; i < n; i++) {
            totalSum += nums[i];
        }

        if(totalSum % 2 == 1) return false;

        int target = totalSum / 2;
        vector<vector<bool>> dp(n + 1, vector<bool>(target + 1, false));
        return solve(n - 1, nums, target, dp);
    }
};
