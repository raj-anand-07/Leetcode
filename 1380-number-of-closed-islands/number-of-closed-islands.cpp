class Solution {
public:
    void dfs(vector<vector<int>>& grid, vector<vector<int>>& visited, int row, int col, int n, int m) {
        visited[row][col] = 1;

        vector<vector<int>> dir = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

        for(int i = 0; i < 4; i++) {
            int nrow = row + dir[i][0];
            int ncol = col + dir[i][1];

            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !visited[nrow][ncol] && grid[nrow][ncol]==0) {
                dfs(grid, visited, nrow, ncol, n, m);
            }
        }
    }

    int closedIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> visited(n, vector<int>(m, 0));

        for(int i = 0; i < m; i++) {
            if(grid[0][i] == 0 && !visited[0][i]) {
                dfs(grid, visited, 0, i, n, m);
            }

            if(grid[n - 1][i] == 0 && !visited[n - 1][i]) {
                dfs(grid, visited, n - 1, i, n, m);
            }
        }

        for(int j = 0; j < n; j++) {
            if(grid[j][0] == 0 && !visited[j][0]) {
                dfs(grid, visited, j, 0, n, m);
            }

            if(grid[j][m - 1] == 0 && !visited[j][m - 1]) {
                dfs(grid, visited, j, m - 1, n, m);
            }
        }

        int ans = 0;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 0 && !visited[i][j]) {
                    dfs(grid, visited, i, j, n, m);
                    ans++;
                }
            }
        }

        return ans;
    }
};