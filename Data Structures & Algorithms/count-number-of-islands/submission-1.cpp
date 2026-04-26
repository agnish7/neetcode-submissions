class Solution {
    int dirs[4][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
public:
    int numIslands(vector<vector<char>>& grid) {
        int counter = '2';
        for(int i = 0; i < grid.size(); ++i) {
            for(int j = 0; j < grid[0].size(); ++j) {
                if(grid[i][j] == '1') {
                    dfs(grid, i, j, counter);
                    ++counter;
                }
            }
        }
        // for(auto& i: grid) {
        //     for(auto& e: i) {
        //         cout << e << " ";
        //     }
        //     cout << endl;
        // }
        return counter - 2 - '0';
    }
    void dfs(vector<vector<char>>& grid, int r, int c, char counter) {
        if(grid[r][c] == '0') return;
        if(grid[r][c] == counter) return;
        int m = grid.size(), n = grid[0].size();
        // cout << r << " " << c << endl;
        grid[r][c] = counter;
        for(int i = 0; i < 4; ++i) {
            int x = r + dirs[i][0];
            int y = c + dirs[i][1];
            if(x >= 0 && x < m && y >= 0 && y < n) dfs(grid, x, y, counter);
        }
    }
};
