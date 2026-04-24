class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int k = s1.size();
        int n = s2.size();

        if(k > n) return false;

        vector<int> countS1(26, 0);
        vector<int> countS2(26, 0);

        for(int i = 0; i < k; i++) {
            countS1[s1[i] - 'a']++;
            countS2[s2[i] - 'a']++;
        }

        if(countS1 == countS2) return true;

        for(int i = k; i < n; i++) {
            countS2[s2[i] - 'a']++;
            countS2[s2[i - k] - 'a']--;
            if(countS1 == countS2) return true;
        }
        return false;
    }
};
