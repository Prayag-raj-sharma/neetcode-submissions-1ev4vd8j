class Solution {
private:
    int solve(int index, vector<int>& nums, int sum, int target, int offset, vector<vector<int>>& dp) {
        if(index == nums.size()) {
            return sum == target ? 1 : 0;
        }

        int sumIndex = sum + offset;

        if(dp[index][sumIndex] != -1) return dp[index][sumIndex];

        int pos = solve(index + 1, nums, sum + nums[index], target, offset, dp);
        int neg = solve(index + 1, nums, sum - nums[index], target, offset, dp);

        return dp[index][sumIndex] = pos + neg;
    }
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int total = 0;
        for(auto n: nums) {
            total += n;
        }

        // edge case
        if(abs(target) > total) return 0;

        int offset = total;

        vector<vector<int>> dp(n + 1, vector<int>(2 * total + 1, -1));
        return solve(0, nums, 0, target, offset, dp);
        
    }
};
