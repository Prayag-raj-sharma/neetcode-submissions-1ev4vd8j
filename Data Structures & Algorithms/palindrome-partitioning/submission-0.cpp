class Solution {
private:
    void solve(int start, string s, vector<string>& pal, 
    vector<vector<string>>& result) {
        if(start == s.size()) {
            result.push_back(pal);
            return;
        }

        for(int i = start; i < s.size(); i++) {
            if(isPalindrome(start, i, s)) {
                pal.push_back(s.substr(start, i - start + 1));
                solve(i + 1, s, pal, result);
                pal.pop_back();
            }
        }
    }
    bool isPalindrome(int start, int end, string s) {
        while(start < end) {
            if(s[start] != s[end]) {
                return false;
            }
            start++;
            end--;
        }
        return true;
    }
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> result;

        vector<string> pal;

        solve(0, s, pal, result);
        return result;  
    }
};
