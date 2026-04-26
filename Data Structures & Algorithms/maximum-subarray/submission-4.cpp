class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        return dp(nums, 0, true);
    }
    int dp(vector<int>& nums, int i, bool end) {
        if(i == nums.size()) {
            return end ? INT_MIN : 0;
        }
        int res = 0;
        if(end) {
            res =  max(nums[i] + dp(nums, i + 1, false), dp(nums, i + 1, true));
        } else {
            res = max(0, nums[i] + dp(nums, i + 1, false));
        }
        return res;
    }
};
