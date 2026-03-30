class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) return false;

        vector<int> freq(256, 0);
        for(auto ch: s) {
            freq[ch - 'a']++;
        }

        for(auto ch: t) {
            freq[ch - 'a']--;
        }

        for(int i = 0; i < 256; i++) {
            if(freq[i] < 0) {
                return false;
            }
        }
        return true;   
    }
};
