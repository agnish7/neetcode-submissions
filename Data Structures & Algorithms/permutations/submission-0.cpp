class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        unordered_set<int> remaining(nums.begin(), nums.end());
        vector<vector<int>> res;
        vector<int> permutation;
        backtrack(res, nums.size(), permutation, remaining);
        return res;
    }

    void backtrack(vector<vector<int>>& res, int size, vector<int> permutation, unordered_set<int> remaining) {
        if(permutation.size() == size) {
            res.push_back(permutation);
            return;
        }
        unordered_set<int> temp = remaining;
        for(auto& r: remaining) {
            permutation.push_back(r);
            temp.erase(r);
            backtrack(res, size, permutation, temp);
            temp.insert(r);
            permutation.pop_back();
        }
    }
};
