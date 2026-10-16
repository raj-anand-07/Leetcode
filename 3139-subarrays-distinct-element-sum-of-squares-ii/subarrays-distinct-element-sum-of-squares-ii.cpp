class Solution {
    static const int MOD = 1e9 + 7;
    vector<long long> s, q, lz;

    void apply(int o, int l, int r, long long v) {
        long long len = r - l + 1;
        q[o] = (q[o] + 2 * v % MOD * s[o] + v * v % MOD * len) % MOD;
        s[o] = (s[o] + v * len) % MOD;
        lz[o] += v;
    }

    void update(int o, int l, int r, int L, int R) {
        if (L <= l && r <= R) {
            apply(o, l, r, 1);
            return;
        }
        int m = (l + r) / 2;
        if (lz[o]) {
            apply(2 * o, l, m, lz[o]);
            apply(2 * o + 1, m + 1, r, lz[o]);
            lz[o] = 0;
        }
        if (L <= m) update(2 * o, l, m, L, R);
        if (R > m) update(2 * o + 1, m + 1, r, L, R);
        s[o] = (s[2 * o] + s[2 * o + 1]) % MOD;
        q[o] = (q[2 * o] + q[2 * o + 1]) % MOD;
    }

public:
    int sumCounts(vector<int>& nums) {
        int n = nums.size();
        s.assign(4 * n, 0);
        q.assign(4 * n, 0);
        lz.assign(4 * n, 0);

        unordered_map<int, int> last;
        long long ans = 0;
        for (int i = 0; i < n; i++) {
            auto it = last.find(nums[i]);
            int prev = (it == last.end()) ? -1 : it->second;
            update(1, 0, n - 1, prev + 1, i);
            last[nums[i]] = i;
            ans = (ans + q[1]) % MOD;
        }
        return (int)ans;
    }
};