class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        unordered_set<int>(nums.begin(), nums.end());
        vector<vector<int>> res;
        res.push_back(vector<int>({}));
        for(auto& e: nums) {
            vector<vector<int>> new_res;
            for(int i = 0; i < res.size(); ++i) {
                vector<int> temp = res[i];
                temp.push_back(e);
                new_res.push_back(temp);
            }
            for(int i = 0; i < new_res.size(); ++i) {
                res.push_back(new_res[i]);
            }
        }
        return res;
    }
};
