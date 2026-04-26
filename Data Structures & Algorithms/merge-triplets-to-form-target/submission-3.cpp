class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        vector<int> curr(3, -1);
        for(int i = 0; i < triplets.size(); ++i) {
            if(triplets[i][0] > target[0] ||
            triplets[i][1] > target[1] ||
            triplets[i][2] > target[2])
                continue;

            for(int j = 0; j < 3; ++j) {
                curr[j] = max(curr[j], triplets[i][j]);
                cout << curr[j] << " ";
            }
            cout << endl;



            if(curr[0] == target[0] && curr[1] == target[1] && curr[2] == target[2])
                return true;
        }
        return false;
    }
};
