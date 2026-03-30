class Solution {
private:
    string expandAtCenter(string& s, int left, int right) {
        while(left >= 0 && right < s.size() && s[left] == s[right]) {
            left--;
            right++;
        }
        return s.substr(left + 1, right - left - 1);
    }
public:
    string longestPalindrome(string s) {
        string result = "";

        for(int i = 0; i < s.size(); i++) {
            string odd = expandAtCenter(s, i, i);
            string even = expandAtCenter(s, i, i + 1);

            if(even.size() > result.size()) {
                result = even;
            }
            if(odd.size() > result.size()) {
                result = odd;
            }
        }
        return result;
    }
};
