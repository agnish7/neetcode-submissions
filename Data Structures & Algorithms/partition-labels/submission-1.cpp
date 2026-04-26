class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> partitions;
        vector<int> res;
        unordered_map<char, vector<int>> firstLast;
        for(int i = 0; i < s.size(); ++i) {
            if(firstLast.count(s[i])) {
                firstLast[s[i]][1] = i;
            } else {
                firstLast[s[i]] = {i, i};
            }
        }

        for(int i = 0; i < s.size(); ++i) {
            bool check = true;
            for(auto& p: firstLast) {
                check = check && ((i > p.second[0] && i >= p.second[1]) || (i < p.second[0] && i < p.second[1]) || (i == p.second[0] && i == p.second[1]));
                // cout << check << " " << i << " " << p.second[0] << " " << p.second[1] << endl;
            }
            if(check)
                partitions.push_back(i);
        }

        res.push_back(partitions[0] + 1);
        for(int i = 1; i < partitions.size(); ++i) {
            res.push_back(partitions[i] - partitions[i - 1]);
        }
        
        return res;
    }
};
