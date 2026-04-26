class Solution {
    int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int res = 0;
        for(int r = 0; r < grid.size(); ++r) {
            for(int c = 0; c < grid[0].size(); ++c) {
                if(grid[r][c]) res = max(res, dfs(grid, r, c));
            }
        }
        return res;
    }
    int dfs(vector<vector<int>>& grid, int r, int c) {
        int m = grid.size(), n = grid[0].size();
        grid[r][c] = 0;
        int res = 0;
        for(int i = 0; i < 4; ++i) {
            int x = r + dirs[i][0], y = c + dirs[i][1];
            if(x >= 0 && x < m && y >= 0 && y < n && grid[x][y] == 1)
                res += dfs(grid, x, y);
        }
        return res + 1;
    }
};
