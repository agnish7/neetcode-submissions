class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        vector<vector<int>> cache(matrix.size(), vector<int>(matrix[0].size(), 0));
        int res = INT_MIN;
        for(int i = 0; i < matrix.size(); ++i) {
            for(int j = 0; j < matrix[0].size(); ++j) {
                res = max(res, backtrack(matrix, i, j, {}, -1, cache));
            }
        }

        // for(int i = 0; i < cache.size(); ++i) {
        //     for(int j = 0; j < cache[0].size(); ++j) {
        //         cout << cache[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        return res;
    }

    int backtrack(vector<vector<int>>& matrix, int r, int c, unordered_set<string> visited, int prev, vector<vector<int>>& cache) {
        if(r < 0 || c < 0 || r >= matrix.size() || c >= matrix[0].size()) {
            return 0;
        }
        int res = -1;
        if(visited.count(to_string(r) + "#" + to_string(c)) || prev >= matrix[r][c]) {
            return 0;
        } else if (cache[r][c] != 0){
            return cache[r][c];
        } else {
            visited.insert(to_string(r) + "#" + to_string(c));
            vector<int> temp = {
                1 + backtrack(matrix, r + 1, c, visited, matrix[r][c], cache),
                1 + backtrack(matrix, r - 1, c, visited, matrix[r][c], cache),
                1 + backtrack(matrix, r, c + 1, visited, matrix[r][c], cache),
                1 + backtrack(matrix, r, c - 1, visited, matrix[r][c], cache)
            };
            res = *max_element(temp.begin(), temp.end());
        }
        cache[r][c] = res;
        return res;
    }
};
