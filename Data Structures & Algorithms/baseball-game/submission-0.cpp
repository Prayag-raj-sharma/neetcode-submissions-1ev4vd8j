class Solution {
public:
    int calPoints(vector<string>& operations) {
        int n = operations.size();
        stack<int> st;
        int sum = 0;

        for(int i = 0; i < n; i++) {
            string op = operations[i];
            if(op == "D") {
                int val = st.top() * 2;
                st.push(val);
            } else if(op == "C") {
                st.pop();
            } else if(op == "+") {
                int val1 = st.top(); st.pop();
                int val2 = st.top() + val1;
                st.push(val1);
                st.push(val2);
            } else {
                st.push(stoi(op));
            }
        }
        while(!st.empty()) {
            sum += st.top();
            st.pop();
        }
        return sum;  
    }
};