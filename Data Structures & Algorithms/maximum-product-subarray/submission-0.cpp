class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int maxProduct = nums[0];
        int minProduct = nums[0];
        int ans = nums[0];

        for(int i = 1; i < n; i++) {
            int num = nums[i];
            int temp = maxProduct;

            maxProduct = max({num, num * maxProduct, num * minProduct});
            minProduct = min({num, num * temp, num * minProduct});

            ans = max(ans, maxProduct);
        }
        return ans;
    }
};
