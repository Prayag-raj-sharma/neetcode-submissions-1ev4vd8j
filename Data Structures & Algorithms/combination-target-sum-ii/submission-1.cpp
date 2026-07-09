class Solution {
private:
    void solve(int index, vector<int>& can, vector<int>& ans,
               vector<vector<int>>& result, int target) {
        if(target == 0) {
            result.push_back(ans);
            return;
        }

        for(int i = index; i < can.size(); i++) {
            if(i > index && can[i] == can[i - 1]) {
                continue;
            }
            if(can[i] > target) break;

            ans.push_back(can[i]);
            solve(i + 1, can, ans, result, target - can[i]);
            ans.pop_back();
        }

    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> ans;
        sort(candidates.begin(), candidates.end());
        solve(0, candidates, ans, result, target);
        return result;
    }
};
