/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        sort(intervals.begin(), intervals.end(), [](Interval a, Interval b){
            return a.start < b.start;
        });
        return dfs(intervals);
    }
    int dfs(vector<Interval> intervals) {
        if(intervals.size() == 0) {
            return 0;
        }
        if(intervals.size() == 1) {
            return 1;
        }
        vector<Interval> nextDay;
        int n = intervals.size();
        Interval prev = intervals[0];
        for(int i = 1; i < n; ++i) {
            Interval curr = intervals[i];
            if(prev.end  > curr.start) {
                if(prev.end > curr.end) {
                    nextDay.push_back(prev);
                    prev = curr;
                } else {
                    nextDay.push_back(curr);
                }
            } else 
                prev = curr;
        }

        return 1 + dfs(nextDay);
    }
};
