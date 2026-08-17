class Solution {
private:
    void solve(int index, int len, vector<int>& nums, vector<int>& subset, vector<vector<int>>& result) {
        if(index >= len) {
            result.push_back(subset);
            return;
        }

        subset.push_back(nums[index]);
        solve(index + 1, len, nums, subset, result);
        subset.pop_back();

        while(index + 1 < len && nums[index] == nums[index + 1]) {
            index++;
        }
        solve(index + 1, len, nums, subset, result);
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<int> subset;
        vector<vector<int>> result;
        solve(0, n, nums, subset, result);
        return result; 
    }
};
