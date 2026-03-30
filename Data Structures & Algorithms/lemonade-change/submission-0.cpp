class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int n = bills.size();
        int fives = 0, tens = 0;

        for(int i = 0; i < n; i++) {
            int bill = bills[i];
            if(bill == 5) {
                fives++;
            } else if(bill == 10) {
                if(fives < 1) return false;
                tens++;
                fives--;
            } else if(bill == 20) {
                if(fives && tens) {
                    fives--;
                    tens--;
                } else if(fives >= 3) {
                    fives -= 3;
                } else return false;
            }
        }
        return true;  
    }
};