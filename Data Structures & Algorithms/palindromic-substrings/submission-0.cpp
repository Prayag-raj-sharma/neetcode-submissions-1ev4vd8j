class Solution {
private:
    int expand(string& s, int left, int right) {
        int count = 0;
        while(left >= 0 && right < s.size() && s[left] == s[right]) {
            count++;
            left--;
            right++;
        }
        return count;
    }
public:
    int countSubstrings(string s) {
        int size = s.size();
        int count = 0;

        for(int i = 0; i < size; i++) {
            count += (expand(s, i, i) + expand(s, i, i + 1));
        }
        return count;
    }
};
