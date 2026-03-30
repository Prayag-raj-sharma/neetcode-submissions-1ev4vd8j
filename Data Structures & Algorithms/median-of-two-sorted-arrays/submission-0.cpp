class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size() > nums2.size()) return findMedianSortedArrays(nums2, nums1);
        int n = nums1.size();
        int m = nums2.size();
        int l = 0, r = n;

        while(l <= r) {
            int partX = (l + r) / 2;
            int partY = (n + m + 1) / 2 - partX;

            int leftMaxX = (partX == 0) ? INT_MIN: nums1[partX - 1];
            int rightMinX = (partX == n) ? INT_MAX: nums1[partX];

            int leftMaxY = (partY == 0) ? INT_MIN: nums2[partY - 1];
            int rightMinY = (partY == m) ? INT_MAX: nums2[partY];

            if(leftMaxX <= rightMinY && leftMaxY <= rightMinX) {
                if((n + m) % 2 == 0) {
                    return (max(leftMaxX, leftMaxY) + min(rightMinX, rightMinY)) / 2.0;
                } else {
                    return max(leftMaxX, leftMaxY);
                }
            } else if(leftMaxX > rightMinY) {
                r = partX - 1;
            } else {
                l = partX + 1;
            }
        }
        return 0.0; 
    }
};
