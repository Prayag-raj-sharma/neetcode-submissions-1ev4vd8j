class Solution {
private:
    int solve(int n) {
        int sum = 0;

        while(n) {
            int lastDigit = n % 10;

            sum += (lastDigit * lastDigit);

            n /= 10;
        }
        return sum;
    }
public:
    bool isHappy(int n) {
        int slow = n;
        int fast = solve(n);
        while(slow != 1 && fast != slow) {
            slow = solve(slow);
            fast = solve(solve(fast));
        }
        
        return slow == 1;
    }
};
