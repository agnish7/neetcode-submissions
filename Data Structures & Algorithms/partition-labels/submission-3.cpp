class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char, int> lastOccurrence;
        vector<int> res;
        for(int i = 0; i < s.size(); ++i) {
            lastOccurrence[s[i]] = i;
        }
        // for(auto& p: lastOccurrence) {
        //     cout << p.first << " " << p.second << endl;
        // }

        int end = -1;
        int partition_size = 0;
        for(int i = 0; i < s.size(); ++i) {
            end = max(end, lastOccurrence[s[i]]);
            ++partition_size;
            if(i == end) {
                res.push_back(partition_size);
                partition_size = 0;
            }
        }

        return res;
    }
};
