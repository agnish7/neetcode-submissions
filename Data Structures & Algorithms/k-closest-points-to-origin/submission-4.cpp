class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<int> distances;
        unordered_map<int, vector<vector<int>>> distance_to_points;

        for(auto& point: points) {
            int d = distance(point);
            if(distances.size() < k) {
                distances.push(d);
                distance_to_points[d].push_back(point);
                continue;
            }

            if(d < distances.top()) {
                distance_to_points.erase(distances.top());
                distances.pop();
                distances.push(d);
                distance_to_points[d].push_back(point);
            }
        }

        vector<vector<int>> res;
        while(!distances.empty()) {
            int d = distances.top();
            distances.pop();
            for(auto& point: distance_to_points[d]) {
                res.push_back(point);
                if(res.size() == k) return res;
            }
        }

        return res;

    }
    int distance(vector<int>& a) {
        return a[0] * a[0] + a[1] * a[1];
    }
};
