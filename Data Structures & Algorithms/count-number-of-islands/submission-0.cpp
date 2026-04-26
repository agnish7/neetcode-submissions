class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int res = 0;
        for(int i = 0; i < grid.size(); ++i) {
            for(int j = 0; j < grid[0].size(); ++j) {
                if(grid[i][j] == '1') {
                    ++res;
                    dfs(grid, i, j);
                } else {
                    continue;
                }
            }
        }
        return res;
    }
    void dfs(vector<vector<char>>& grid, int r, int c) {
        if(r < 0 || c < 0 || r >= grid.size() || c >= grid[0].size() || grid[r][c] == '0') {
            return;
        }
        grid[r][c] = '0';
        dfs(grid, r + 1, c);
        dfs(grid, r - 1, c);
        dfs(grid, r, c - 1);
        dfs(grid, r, c + 1);
    }
};
