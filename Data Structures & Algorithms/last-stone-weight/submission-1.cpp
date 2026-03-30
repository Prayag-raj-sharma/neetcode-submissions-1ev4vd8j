class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        int n = stones.size();
        priority_queue<int> pq(stones.begin(), stones.end());

    
        while(pq.size() >= 2) {
            int first = pq.top(); pq.pop();
            int second = pq.top(); pq.pop();

            if(first == second) continue;
            first > second? pq.push(first - second) 
                          : pq.push(second - first);
        }
        
        if(pq.size() > 0) return pq.top();
        return 0;   
    }
};
