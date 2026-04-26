class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if(amount == 0) {
            return 0;
        }
        unordered_map<int, int> amount_numCoins;
        for(auto& coin : coins) {
            amount_numCoins[coin] = 1;
        }
        return backtrack(amount, coins, amount_numCoins);
    }
    int backtrack(int amount, vector<int>& coins, unordered_map<int, int>& amount_numCoins) {
        // cout << "Sub problem: " << amount << endl;
        if(amount_numCoins.count(amount)) {
            // cout << "Cache hit: " << amount_numCoins[amount]<< endl;
            return amount_numCoins[amount];
        }
        if(amount < 0) {
            return -1;
        }
        int minCoins = INT_MAX;
        for(auto& coin: coins) {
            int calcCoins = backtrack(amount - coin, coins, amount_numCoins);
            if(calcCoins == -1) {
                continue;
            }
            minCoins = min(minCoins, calcCoins);
        }
        int res = minCoins == INT_MAX ? -1 : minCoins + 1;
        // cout << "Result: " << endl;
        amount_numCoins[amount] = res;
        return res;
    }
};
