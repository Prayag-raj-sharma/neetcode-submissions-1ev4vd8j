class Solution {
public:
    bool isPalindrome(string s) {
        string validS = "";
        for(auto x: s) {
            if(x >= 'A' && x <= 'Z' ||
               x >= 'a' && x <= 'z' ||
               x >= '0' && x <= '9') {
                validS += tolower(x);
            }
        }

        int i = 0, j = validS.size() - 1;

        while(i < j) {
            if(validS[i] != validS[j]) {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
};
