class Solution {
public:
    int jump(vector<int>& nums) {
        vector<int> dp(nums.size(), 0);
        for(int i = nums.size() - 2; i > -1; --i) {
            int minSteps = 1000;
            if(nums[i] + i == nums.size() - 1) {
                minSteps = 0;
            } else {
                for(int j = i + 1; j <= nums[i] + i && j < nums.size(); ++j) {
                    minSteps = min(minSteps, dp[j]);
                }
            }
            dp[i] = 1 + minSteps;
        }
        // for(auto& i : dp) {
        //     cout << i << " ";
        // }
        return dp[0];
    }
};
