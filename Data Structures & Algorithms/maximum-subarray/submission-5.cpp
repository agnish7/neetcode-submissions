class Solution {
    vector<vector<int>> cache;
public:
    int maxSubArray(vector<int>& nums) {
        cache.assign(nums.size(), vector<int>(2, INT_MIN));
        return dp(nums, 0, true);
    }
    int dp(vector<int>& nums, int i, bool end) {
        if(i == nums.size()) {
            return end ? INT_MIN : 0;
        }
        if(cache[i][end] != INT_MIN) {
            return cache[i][end];
        }
        int res = 0;
        if(end) {
            res =  max(nums[i] + dp(nums, i + 1, false), dp(nums, i + 1, true));
        } else {
            res = max(0, nums[i] + dp(nums, i + 1, false));
        }
        cache[i][end] = res;
        return res;
    }
};
