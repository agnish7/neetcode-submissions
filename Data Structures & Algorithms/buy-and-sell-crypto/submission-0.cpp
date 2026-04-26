class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int curr_min = INT_MAX;
        int max_diff = INT_MIN;
        for(int i = 0; i < prices.size(); ++i) {
            curr_min = std::min(curr_min, prices[i]);
            max_diff = std::max(max_diff, prices[i] - curr_min);
        }
        return std::max(max_diff, 0);
    }
};
