class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0), n = nums.size();
        if(sum % 2 != 0)
            return false;
        int target = sum / 2;
        vector<vector<bool>> res(target + 1, vector<bool>(n, false));

        for(int i = 0; i < n; ++i) {
            res[0][i] = true;
        }

        for(int t = 1; t <= target; ++t) {
            res[t][n - 1] = (t - nums[n - 1] == 0);
        }

        for(int t = 1; t <= target; ++t) {
            for(int i = n - 2; i > -1; --i) {
                if(t - nums[i] >= 0)
                    res[t][i] = res[t - nums[i]][i + 1] || res[t][i + 1];
                else
                    res[t][i] = res[t][i + 1];
            }
        }

        return res[target][0];
    }
};
