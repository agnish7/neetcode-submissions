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
        vector<int> start;
        vector<int> end;
        
        for (const auto& interval : intervals) {
            start.push_back(interval.start);
            end.push_back(interval.end);
        }
        
        sort(start.begin(), start.end());
        sort(end.begin(), end.end());



        for(auto& s: start) cout << s << " ";
        cout << endl;

        for(auto& e: end) cout << e << " ";
        cout << endl;

        int s = 0, e = 0;
        int rooms = 0;

        int days = 0;

        while(s < start.size() && e < end.size()) {
            if(start[s] < end[e]) {
                ++rooms;
                ++s;
            } else {
                --rooms;
                ++e;
            }
            days = max(days, rooms);
        }

        return days;
    }
};
