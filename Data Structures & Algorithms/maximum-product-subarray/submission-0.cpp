class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxProd = INT_MIN;
        int l_prod = 1;
        int r_prod = 1;
        for(int i = 0; i < nums.size(); ++i) {
            if(nums[i] == 0) {
                l_prod = r_prod = 1;
            }
            l_prod = l_prod * nums[i];
            r_prod = r_prod * nums[nums.size() - 1 - i];
            maxProd = max(maxProd, max(l_prod, r_prod));
        }
        return maxProd;
    }
};
