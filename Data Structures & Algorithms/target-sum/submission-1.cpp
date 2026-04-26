class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        unordered_map<string, int> cache;
        return backtrack(target, 0, 0, nums, cache);
    }
    
    int backtrack(int target, int sum, int i, vector<int>& nums, unordered_map<string, int>& cache) {
        if(cache.count(to_string(sum) + "#" + to_string(i))) {
            return cache[to_string(sum) + "#" + to_string(i)];
        }
        int res = -1;
        if(target == sum && i == nums.size()) {
            res = 1;
        }else if(i == nums.size()) {
            res = 0;
        } else 
            res = backtrack(target, sum + nums[i], i + 1, nums, cache) + backtrack(target, sum - nums[i], i + 1, nums, cache);
        cache[to_string(sum) + "#" + to_string(i)] = res;
        return res;
    }
};
