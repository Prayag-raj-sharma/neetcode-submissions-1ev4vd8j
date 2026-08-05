class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int n = arr.size();
        int sum = 0;
        int avg = 0;
        int count = 0;

        int L = 0;
        for(int R = 0; R < k; R++) {
            sum += arr[R];
        }

        avg = sum / k;
        if(avg >= threshold) {
            count++;
        }

        for(int R = k; R < n; R++) {
            sum -= arr[L++];
            sum += arr[R];
            avg = sum / k;
            if(avg >= threshold) {
                count++;
            }
        }
        return count;
    }
};