class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        vector<int> currCombo;
        backtrack(res, nums, target, 0, currCombo, 0);
        return res;
    }

    void backtrack(vector<vector<int>>& res, vector<int>& nums, int& target, int currSum, vector<int> currCombo, int i) {
        if(i == nums.size()) {
            return;
        }
        if(currSum > target) {
            return;
        }
        if(currSum == target) {
            res.push_back(currCombo);
            return;
        }
        currCombo.push_back(nums[i]);
        backtrack(res, nums, target, currSum + nums[i], currCombo, i);
        currCombo.pop_back();
        backtrack(res, nums, target, currSum, currCombo, i + 1);
    }
};
