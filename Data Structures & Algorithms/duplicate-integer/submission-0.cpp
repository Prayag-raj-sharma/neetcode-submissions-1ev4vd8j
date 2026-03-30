class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        set<int> store;
        for(auto x: nums) {
            if(store.count(x)) {
                return true;
            }
            store.insert(x);
        }
        return false;  
    }
};