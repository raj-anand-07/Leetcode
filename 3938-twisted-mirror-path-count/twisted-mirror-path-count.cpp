class Solution {
public:
    int uniquePaths(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        const int MOD = 1e9 + 7;

        // dp[i][j][0] -> entered while moving right
        // dp[i][j][1] -> entered while moving down
        vector<vector<vector<int>>> dp(
            m, vector<vector<int>>(n, vector<int>(2, 0))
        );

        // First move: right or down
        dp[0][1][0] = 1;
        dp[1][0][1] = 1;

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {

                for(int d = 0; d < 2; d++) {

                    int ways = dp[i][j][d];

                    if(ways == 0) continue;

                    if(grid[i][j] == 0) {

                        // Move right
                        if(j + 1 < n) {
                            dp[i][j+1][0] =
                                (dp[i][j+1][0] + ways) % MOD;
                        }

                        // Move down
                        if(i + 1 < m) {
                            dp[i+1][j][1] =
                                (dp[i+1][j][1] + ways) % MOD;
                        }

                    }
                    else {

                        // Mirror: entered from left
                        if(d == 0 && i + 1 < m) {
                            dp[i+1][j][1] =
                                (dp[i+1][j][1] + ways) % MOD;
                        }

                        // Mirror: entered from above
                        else if(d == 1 && j + 1 < n) {
                            dp[i][j+1][0] =
                                (dp[i][j+1][0] + ways) % MOD;
                        }
                    }
                }
            }
        }

        return (dp[m-1][n-1][0] + dp[m-1][n-1][1]) % MOD;
    }
};
