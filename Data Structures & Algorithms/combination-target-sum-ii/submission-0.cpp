class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> res;
        backtrack(0, 0, {}, res, target, candidates);
        return res;
    }
    void backtrack(int start, int curr_sum, vector<int> combination, vector<vector<int>>& res, int& target, vector<int>& candidates) {
        if(curr_sum == target) {
            res.push_back(combination);
        }
        for(int i = start; i < candidates.size(); ++i) {
            if(i > start && candidates[i] == candidates[i - 1]) {
                continue;
            }
            combination.push_back(candidates[i]);
            curr_sum += candidates[i];
            backtrack(i + 1, curr_sum, combination, res, target, candidates);
            curr_sum -= candidates[i];
            combination.pop_back();
        }
    }
};
