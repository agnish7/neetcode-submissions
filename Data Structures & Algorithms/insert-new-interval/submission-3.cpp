class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> res;
        auto pos = lower_bound(intervals.begin(), intervals.end(), newInterval[0], [](vector<int> a, int v){
            return a[0] < v;
        });

        int n = intervals.size();

        if(!n) {
            return {newInterval};
        }

        int idx = distance(intervals.begin(), pos);
        int l = idx, r = idx - 1 >= 0 ? idx - 1 : 0;

        while(r + 1 < n && intervals[r + 1][0] <= newInterval[1]) {
            ++r;
        }
        while(l - 1 > -1 && intervals[l - 1][1] >= newInterval[0]) {
            --l;
        }

        // cout << idx << " " << l << " " << r << endl;

        vector<int> merged{min(l < idx ? intervals[l][0] : INT_MAX, newInterval[0]), 
            newInterval[1] >= intervals[r][0] ? max(intervals[r][1], newInterval[1]) : newInterval[1]};

        for(int i = 0; i < l; ++i) {
            res.push_back(intervals[i]);
        }
        res.push_back(merged);
        for(int i = newInterval[1] >= intervals[r][0] ? r + 1 : r; i < n; ++i) {
            res.push_back(intervals[i]);
        }
        return res;
    }
};
