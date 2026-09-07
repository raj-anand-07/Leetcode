class Solution {
public:
    int mod = 1e9 + 7;

    int solveMem(int i, vector<int>& dp, vector<int>& prev) {
        if(i == 0) {
            return 1;
        }

        if(dp[i] != -1) {
            return dp[i];
        }

        int total = (2 * solveMem(i - 1, dp, prev)) % mod;

        if(prev[i] != 0) {
            int duplicates = (solveMem(prev[i] - 1, dp, prev)) % mod;
            total = (total - duplicates + mod) % mod;
        }

        return dp[i] = total;
    }

    int distinctSubseqII(string s) {
        int n = s.size();

        vector<int> lastSeen(26, 0);
        vector<int> prev(n + 1, 0);

        for(int i = 1; i <= n; i++) {
            int idx = s[i - 1] - 'a';

            prev[i] = lastSeen[idx];
            lastSeen[idx] = i;
        }

        vector<int> dp(n + 1, -1);

        return (solveMem(n, dp, prev) - 1 + mod) % mod;
    }
};