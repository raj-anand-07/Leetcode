class Solution {
    using ll = long long;

    int LOG;
    vector<vector<int>> adj, up;
    vector<int> depth, tin, tout;
    vector<int> bit;
    string s;
    int timer = 0;

    int mask(char c) {
        return 1 << (c - 'a');
    }

    void add(int i, int val, int n) {
        for (; i <= n; i += i & -i)
            bit[i] ^= val;
    }

    int query(int i) {
        int res = 0;
        for (; i > 0; i -= i & -i)
            res ^= bit[i];
        return res;
    }

    void rangeXor(int l, int r, int val, int n) {
        add(l, val, n);
        if (r + 1 <= n)
            add(r + 1, val, n);
    }

    int pointQuery(int i) {
        return query(i);
    }

    void dfs(int u, int p) {
        tin[u] = ++timer;
        up[0][u] = p;

        for (int k = 1; k < LOG; k++)
            up[k][u] = up[k - 1][up[k - 1][u]];

        for (int v : adj[u]) {
            if (v == p) continue;
            depth[v] = depth[u] + 1;
            dfs(v, u);
        }

        tout[u] = timer;
    }

    int lca(int u, int v) {
        if (depth[u] < depth[v])
            swap(u, v);

        int diff = depth[u] - depth[v];

        for (int k = 0; k < LOG; k++)
            if (diff & (1 << k))
                u = up[k][u];

        if (u == v) return u;

        for (int k = LOG - 1; k >= 0; k--) {
            if (up[k][u] != up[k][v]) {
                u = up[k][u];
                v = up[k][v];
            }
        }

        return up[0][u];
    }

public:
    vector<bool> palindromePath(int n, vector<vector<int>>& edges,
                                string s, vector<string>& queries) {
        this->s = s;

        adj.assign(n, {});
        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        LOG = 1;
        while ((1 << LOG) <= n) LOG++;

        up.assign(LOG, vector<int>(n, 0));
        depth.assign(n, 0);
        tin.assign(n, 0);
        tout.assign(n, 0);
        bit.assign(n + 2, 0);

        // Build the tree's Euler tour and LCA table.
        dfs(0, 0);

        // Initially, store each root-to-node XOR mask.
        vector<int> pref(n, 0);

        for (int u = 0; u < n; u++) {
            pref[tin[u] - 1] = mask(s[u]);
        }

        // Convert node characters into root-prefix masks.
        // Traverse nodes in increasing depth.
        vector<int> order(n);
        iota(order.begin(), order.end(), 0);

        sort(order.begin(), order.end(), [&](int a, int b) {
            return depth[a] < depth[b];
        });

        vector<int> rootMask(n, 0);

        for (int u : order) {
            rootMask[u] = mask(s[u]);
            if (u != 0)
                rootMask[u] ^= rootMask[up[0][u]];
        }

        for (int u = 0; u < n; u++)
            rangeXor(tin[u], tout[u], rootMask[u], n);

        // The structure above is corrected below by using
        // point masks and subtree range differences.
        fill(bit.begin(), bit.end(), 0);

        for (int u = 0; u < n; u++)
            rangeXor(tin[u], tout[u], mask(s[u]), n);

        vector<bool> ans;

        for (string& q : queries) {
            string type;
            int u;
            string third;
            stringstream ss(q);
            ss >> type >> u >> third;

            if (type == "update") {
                char c = third[0];

                int delta = mask(s[u]) ^ mask(c);

                rangeXor(tin[u], tout[u], delta, n);

                s[u] = c;
            } else {
                int v = stoi(third);
                int w = lca(u, v);

                int pathMask =
                    pointQuery(tin[u]) ^
                    pointQuery(tin[v]) ^
                    mask(s[w]);

                ans.push_back(
                    (pathMask & (pathMask - 1)) == 0
                );
            }
        }

        return ans;
    }
};