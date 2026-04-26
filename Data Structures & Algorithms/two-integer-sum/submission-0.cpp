class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> store{};
        for(int i = 0; i < nums.size(); ++i) {
            if(store.find(nums[i]) != store.end()) {
                int first = store[nums[i]];
                int second = i;
                return vector<int> {first, second};
            } else {
                store[target - nums[i]] = i;
            }
        }
        return vector<int> {0, 0};
    }
};
