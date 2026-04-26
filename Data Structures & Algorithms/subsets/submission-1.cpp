class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        backtrack(0, {}, res, nums);
        return res;
    }
    void backtrack(int start, vector<int> subset, vector<vector<int>>& res, vector<int>& nums) {
        res.push_back(subset);
        for(int i = start; i < nums.size(); ++i) {
            subset.push_back(nums[i]);
            backtrack(i + 1, subset, res, nums);
            subset.pop_back();
        }
    }

};
