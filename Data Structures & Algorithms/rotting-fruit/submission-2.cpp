class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int directions[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        queue<pair<int, int>> q;
        for(int r = 0; r < m; ++r) {
            for(int c = 0; c < n; ++c) {
                if(grid[r][c] == 2) q.push({r, c});
            }
        }

        // bfs
        int time = 0;
        while(!q.empty()) {
            int size = q.size();

            for(int i = 0; i < size; ++i) {
                auto curr = q.front();
                q.pop();
                for(auto& dir: directions) {
                    int x = dir[0] + curr.first, y = dir[1] + curr.second;
                    if(x >= 0 && x < m && y >= 0 && y < n && grid[x][y] == 1) {
                        grid[x][y] = 2;
                        q.push({x, y});
                    }
                }
            }

            if(!q.empty()) ++time;

            // for(auto& r: grid) {
            //     for(auto& e: r) {
            //         cout << e << " ";
            //     }
            //     cout << endl;
            // }

            // cout << endl;
        }

        for(int r = 0; r < m; ++r) {
            for(int c = 0; c < n; ++c) {
                if(grid[r][c] == 1) return -1;
            }
        }

        return time;
    }
};
