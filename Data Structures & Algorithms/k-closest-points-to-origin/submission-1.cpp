class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        struct customComparator {
            bool operator() (const vector<int>& v1, const vector<int>& v2) {
                return v1[0] * v1[0] + v1[1] * v1[1] < v2[0] * v2[0] + v2[1] * v2[1];
            }
        };

        priority_queue<vector<int>, vector<vector<int>>, customComparator> pq(points.begin(), points.end());
        
        while(pq.size() > k) {
            pq.pop();
        }

        vector<vector<int>> res;
        while(!pq.empty()) {
            vector<int> point = pq.top();
            res.push_back(point);
            pq.pop();
        }
        return res;
    }
};
