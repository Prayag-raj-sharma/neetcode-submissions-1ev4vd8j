class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int size = tasks.size();
        vector<int> freq(26, 0);

        for(auto t: tasks) {
            freq[t - 'A']++;
        }

        int maxFreq = *max_element(freq.begin(), freq.end());
        int maxCount = 0;

        for(auto f: freq) {
            if(f == maxFreq) {
                maxCount++;
            }
        }

        int ans = (maxFreq - 1) * (n + 1) + maxCount;
        return max(size, ans); 
    }
};
