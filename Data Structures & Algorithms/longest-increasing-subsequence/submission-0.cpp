class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> LIS(n, 1);
        int res = 1;
        for(int i = n - 1; i > -1; --i) {
            int maxLISi = 1;
            for(int j = i + 1; j < n; ++j) {
                // cout << nums[j] << " " << nums[i] << endl;
                if(nums[j] > nums[i]) {
                    maxLISi = max(maxLISi, LIS[j] + 1);
                }
            }
            LIS[i] = maxLISi;
            res = max(res, LIS[i]);
        }
        return res;
    }
};
