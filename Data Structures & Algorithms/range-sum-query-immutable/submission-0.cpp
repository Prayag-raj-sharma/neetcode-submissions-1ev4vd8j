class NumArray {
private: 
    vector<int> prefixSum;
public:
    NumArray(vector<int>& nums) {
        int n = nums.size();
        prefixSum.resize(n);

        prefixSum[0] = nums[0];
        
        for(int i = 1; i < n; i++) {
            prefixSum[i] = prefixSum[i - 1] + nums[i];
        }
    }
    
    int sumRange(int left, int right) {
        int preLeftSum = (left != 0)? prefixSum[left - 1]: 0;
        int preRightSum = prefixSum[right];
        return preRightSum - preLeftSum; 
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */