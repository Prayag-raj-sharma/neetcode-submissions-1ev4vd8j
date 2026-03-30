class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        vector<vector<string>> result;

        for(auto s: strs) {
            string key = s;
            sort(key.begin(), key.end());

            mp[key].push_back(s);
        }

        for(auto m: mp) {
            result.push_back(m.second);
        }
        return result; 
    }
};
