class Solution {
    int directions[4][2] = {
        {-1, 0}, {1, 0},
        {0, -1}, {0, 1}
    };
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {

        for(int r = 0; r < grid.size(); ++r) {
            for(int c = 0; c < grid[0].size(); ++c) {
                if(grid[r][c] == 0) {
                    bfs(r, c, grid);
                }
            }
        }

        // for(auto& r: grid) {
        //     for(auto& e: r) {
        //         cout << e << " ";
        //     }
        //     cout << endl;
        // }
    }

    void bfs(int r, int c, vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        queue<pair<int, int>> q;
        vector<vector<bool>> visited(m, vector<bool>(n, false));

        q.push({r, c});
        int distance = 0;

        while(!q.empty()) {
            int size = q.size();
            ++distance;
            for(int i = 0; i < size; ++i) {
                auto curr = q.front();
                q.pop();
                for(auto& dir: directions) {
                    int x = dir[0] + curr.first, y = dir[1] + curr.second;
                    if(x >= 0  && x < m && y >= 0 && y < n && !visited[x][y] && grid[x][y] > 0) {
                        grid[x][y] = min(grid[x][y], distance);
                        visited[x][y] = true;
                        q.push({x, y});
                    }
                }
            }
        }
    }
};
