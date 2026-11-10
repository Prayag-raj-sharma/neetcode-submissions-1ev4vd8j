class Solution {
public:
    bool isConsecutive(vector<int>& nums) {
        int len = nums.size();
        sort(nums.begin(), nums.end());

        int x = nums[0];
        return x + len - 1 == nums[len - 1];

    }
};
