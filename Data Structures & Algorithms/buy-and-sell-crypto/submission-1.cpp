class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int l = 0, maxP = INT_MIN;
        for(int r = 0; r < prices.size(); ++r) {
            if(prices[r] > prices[l]) {
                maxP = std::max(maxP, prices[r] - prices[l]);
            } else {
                l = r;
            }
        }
        return std::max(maxP, 0);
    }
};
