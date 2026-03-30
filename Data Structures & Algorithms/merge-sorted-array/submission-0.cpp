class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> ans(m + n);
        int i = 0, j = 0;
        int index = 0;

        while(i < m && j < n) {
            if(nums1[i] <= nums2[j]) {
                ans[index] = nums1[i];
                i++;
                index++;
            } else {
                ans[index] = nums2[j];
                j++;
                index++;
            }
        }

        while(i < m) {
            ans[index++] = nums1[i++];
        }

        while(j < n) {
            ans[index++] = nums2[j++];
        }
        
        index = 0;
        while(index < m + n) {
            nums1[index] = ans[index];
            index++;
        } 
    }
};