class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](vector<int> a, vector<int> b){
            return a[0] < b[0];
        });
        vector<vector<int>> res;
        vector<int> newInterval = intervals[0];
        for(int i = 1; i < intervals.size(); ++i) {
            if(newInterval[1] >= intervals[i][0]) {
                newInterval[0] = min(newInterval[0], intervals[i][0]);
                newInterval[1] = max(newInterval[1], intervals[i][1]);
            } else {
                res.push_back(newInterval);
                newInterval = intervals[i];
            }

        }
        res.push_back(newInterval);
        return res;
    }
};
