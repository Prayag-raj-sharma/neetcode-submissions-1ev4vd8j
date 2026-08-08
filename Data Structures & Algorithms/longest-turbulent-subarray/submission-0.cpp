class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int n = arr.size();
        if(n <= 1) return n;

        int maxSize = 1;
        int left = 0;

        int prevSign = 0;

        for(int i = 1; i < n; i++) {
            int currSign = 0;

            if(arr[i - 1] > arr[i]) {
                currSign = -1;
            } else if (arr[i - 1] < arr[i]) {
                currSign = 1;
            }

            if(currSign == 0) left = i;

            else if(currSign == prevSign) {
                left = i - 1;
            }

            maxSize = max(maxSize, i - left + 1);

            prevSign = currSign;
        }
        return maxSize;
    }
};