class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        // for(auto& num: nums) {
        //     cout << num << " ";
        // }
        cout << endl;
        // for(int i = 0; i < nums.size(); ++i) {
        //     cout << i << " ";
        // }
        // cout << endl;
        for(int i = 0; i < nums.size(); ++i) {
            if(i > 0 && nums[i] == nums[i - 1]) continue;
            int l = i + 1, r = nums.size() - 1;
            while(l < r) {
                if(l < r && l > i + 1 && nums[l] == nums[l-1]) {
                    ++l;
                    continue;
                }
                int sum = nums[l] + nums[r] + nums[i];
                //cout << sum << " " << i << " " << l << " " << r << endl;
                if(sum == 0) {
                    res.push_back({nums[i], nums[l], nums[r]});
                    ++l;
                    --r;
                }
                else if(sum < 0) {
                    ++l;
                } else --r;
            }
        }
        return res;
    }
};
