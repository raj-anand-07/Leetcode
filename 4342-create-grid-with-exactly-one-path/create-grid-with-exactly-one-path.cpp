class Solution {
public:
    vector<string> createGrid(int m, int n) {
        vector<string> grid(m, string(n, '#'));

        // fill first row with '.'
        for(int i = 0; i < n; i++) {
            grid[0][i] = '.';
        }

        // fill last column with '.'
        for(int i = 0; i < m; i++) {
            grid[i][n - 1] = '.';
        }

        return grid;
    }
};