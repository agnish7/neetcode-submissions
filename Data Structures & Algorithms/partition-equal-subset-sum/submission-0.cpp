class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum % 2 != 0) {
            return false;
        }
        return check(sum / 2, 0, nums);
    }
    bool check(int target, int idx, vector<int>& nums) {
        if(idx == nums.size()) {
            return target == 0;
        }
        return check(target - nums[idx], idx + 1, nums) || check(target, idx + 1, nums);
    }
};
