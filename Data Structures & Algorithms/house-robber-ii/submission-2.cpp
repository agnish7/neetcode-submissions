class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 1) {
            return nums[0];
        }
        int n = nums.size();
        // left
        int left_max = 0;
        vector<int> dp(n, 0);
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        for(int i = 2; i < n - 1;  ++i) {
            dp[i] = max(nums[i] + dp[i - 2], dp[i - 1]);
        }
        left_max = dp[n - 2];

        // right
        int right_max = 0;
        dp[n - 1] = nums[n - 1];
        dp[n - 2] = max(nums[n - 1], nums[n - 2]);
        for(int i = n - 3; i > 0; --i) {
            dp[i] = max(nums[i] + dp[i + 2], dp[i + 1]);
        }
        right_max = dp[1];

        return max(left_max, right_max);
    }
};
