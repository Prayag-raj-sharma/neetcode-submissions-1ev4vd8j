class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> need, window;

        for(auto c: t) {
            need[c]++;
        }
        int l = 0;
        int have = 0;
        int start = 0;
        int needCount = need.size();
        int minLen = 1e9;

        for(int r = 0; r < s.size(); r++) {
            char ch = s[r];
            window[ch]++;

            if(need.count(ch) && need[ch] == window[ch]) {
                have++;
            }

            while(have == needCount) {
                if(r - l + 1 < minLen) {
                    minLen = r - l + 1;
                    start = l;
                }

                window[s[l]]--;
                if(window.count(s[l]) && window[s[l]] < need[s[l]]) {
                    have--;
                }
                l++;
            }
        }
        return minLen == 1e9? "": s.substr(start, minLen);

        
    }
};
