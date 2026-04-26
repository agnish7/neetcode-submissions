class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        unordered_map<int, int> freq;
        for(auto& num: nums) {
            freq[num]++;
        }

        vector<vector<int>> res;
        res.push_back(vector<int>());

        for(auto& p: freq) {
            vector<vector<int>> combinations;
            for(int i = 1; i <= p.second; ++i) {
                combinations.push_back(vector<int>(i, p.first));
            }

            auto curr_res = res;
            for(auto& cr: curr_res) {
                for(auto& c: combinations) {
                    vector<int> new_combination;
                    new_combination.insert(new_combination.end(), cr.begin(), cr.end());
                    new_combination.insert(new_combination.end(), c.begin(), c.end());
                    res.push_back(new_combination);
                }
            }
        }

        return res;
    }
};
