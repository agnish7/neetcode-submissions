class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        return backtrack(target, 0, 0, nums);
    }
    
    int backtrack(int target, int sum, int i, vector<int>& nums) {
        if(target == sum && i == nums.size()) {
            return 1;
        }
        if(i == nums.size()) {
            return 0;
        }
        return backtrack(target, sum + nums[i], i + 1, nums) + backtrack(target, sum - nums[i], i + 1, nums);
    }
};
