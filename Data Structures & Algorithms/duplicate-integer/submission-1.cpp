class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> store{};
        for(int  i = 0; i < nums.size(); i++) {
            if(store.find(nums[i]) != store.end()) {
                return true;
            }
            store.insert(nums[i]);
        }
        return false;
    }
};
