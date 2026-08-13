class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        vector<vector<int>> result;
        int n = nums.size();

        for (int i = 0; i < n - 2; i++) {
            // No possible triplet can sum to zero after this point.
            if (nums[i] > 0) {
                break;
            }

            // Skip duplicate values for the first number.
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }

            int left = i + 1;
            int right = n - 1;

            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];

                if (sum < 0) {
                    left++;
                } else if (sum > 0) {
                    right--;
                } else {
                    result.push_back({
                        nums[i],
                        nums[left],
                        nums[right]
                    });

                    left++;
                    right--;

                    // Skip duplicate second values.
                    while (left < right &&
                           nums[left] == nums[left - 1]) {
                        left++;
                    }
                }
            }
        }

        return result;
    }
};