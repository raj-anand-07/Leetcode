class Solution {
public:
    int m, n;

    void dfs(vector<vector<int>>& grid, int row, int col) {
        grid[row][col] = 1;

        vector<vector<int>> dir = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

        for(int i = 0; i < 4; i++) {
            int nrow = row + dir[i][0];
            int ncol = col + dir[i][1];

            if(nrow >= 0 && nrow < m && ncol >= 0 && ncol < n && grid[nrow][ncol] == 0) {
                dfs(grid, nrow, ncol);
            }
        }
    }

    int closedIsland(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();

        for(int i = 0; i < m; i++) {
            if(grid[i][0] == 0) {
                dfs(grid, i, 0);
            }

            if(grid[i][n - 1] == 0) {
                dfs(grid, i, n - 1);
            }
        }

        for(int j = 0; j < n; j++) {
            if(grid[0][j] == 0) {
                dfs(grid, 0, j);
            }

            if(grid[m - 1][j] == 0) {
                dfs(grid, m - 1, j);
            }
        }

        int ans = 0;

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 0) {
                    dfs(grid, i, j);
                    ans++;
                }
            }
        }

        return ans;
    }
};