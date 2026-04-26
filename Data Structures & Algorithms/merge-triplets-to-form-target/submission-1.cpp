class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        for(int idx = 0; idx < 3; ++idx) {
            sort(triplets.begin(), triplets.end(), [idx](vector<int> a, vector<int> b){
                return a[idx] > b[idx];
            });
            vector<int> curr(3, -1);
            for(int i = 0; i < triplets.size(); ++i) {
                curr[0] = max(curr[0], triplets[i][0]);
                curr[1] = max(curr[1], triplets[i][1]);
                curr[2] = max(curr[2], triplets[i][2]);

                if(curr[0] == target[0] && curr[1] == target[1] && curr[2] == target[2]) {
                    return true;
                }

                if(curr[0] > target[0] || curr[1] > target[1] || curr[2] > target[2]) {
                    curr[0] = -1;
                    curr[1] = -2;
                    curr[2] = -3;
                }
            }
        }
        return false;
    }
};
