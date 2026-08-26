class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int start = 0;
        int tank = 0;
        int total = 0;

        for(int i = 0; i < n; i++) {
            int gain = gas[i] - cost[i];

            total += gain;
            tank += gain;

            if(tank < 0) {
                start = i + 1;
                tank = 0;
            }
        }
        return total >= 0 ? start : -1; 
    }
};
