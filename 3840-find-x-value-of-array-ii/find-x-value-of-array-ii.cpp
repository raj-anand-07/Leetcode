class Solution {
struct Node {
    int prod = 1;
    long long cnt[5] = {};
};

int n, k_;
vector<Node> tree;

Node mergeNode(const Node& a, const Node& b) {
    Node res;

    res.prod = (a.prod * b.prod) % k_;

    // Prefixes that end inside the left segment
    for (int r = 0; r < k_; ++r)
        res.cnt[r] = a.cnt[r];

    // Prefixes = entire left segment + prefix of right segment
    for (int r = 0; r < k_; ++r) {
        int nr = (a.prod * r) % k_;
        res.cnt[nr] += b.cnt[r];
    }

    return res;
}

Node makeLeaf(long long x) {
    Node res;
    res.prod = x % k_;
    res.cnt[res.prod] = 1;
    return res;
}

void build(int p, int l, int r, const vector<int>& nums) {
    if (l == r) {
        tree[p] = makeLeaf(nums[l]);
        return;
    }

    int m = (l + r) / 2;
    build(p * 2, l, m, nums);
    build(p * 2 + 1, m + 1, r, nums);

    tree[p] = mergeNode(tree[p * 2], tree[p * 2 + 1]);
}

void update(int p, int l, int r, int idx, int val) {
    if (l == r) {
        tree[p] = makeLeaf(val);
        return;
    }

    int m = (l + r) / 2;

    if (idx <= m)
        update(p * 2, l, m, idx, val);
    else
        update(p * 2 + 1, m + 1, r, idx, val);

    tree[p] = mergeNode(tree[p * 2], tree[p * 2 + 1]);
}

Node query(int p, int l, int r, int ql, int qr) {
    if (ql <= l && r <= qr)
        return tree[p];

    int m = (l + r) / 2;

    if (qr <= m)
        return query(p * 2, l, m, ql, qr);

    if (ql > m)
        return query(p * 2 + 1, m + 1, r, ql, qr);

    Node left = query(p * 2, l, m, ql, qr);
    Node right = query(p * 2 + 1, m + 1, r, ql, qr);

    return mergeNode(left, right);
}
public:
    vector<int> resultArray(vector<int>& nums, int k, vector<vector<int>>& queries) {
        k_ = k;
        n = nums.size();

        tree.resize(4 * n);
        build(1, 0, n - 1, nums);

        vector<int> ans;
        ans.reserve(queries.size());

        for (auto& q : queries) {
            int idx   = q[0];
            int value = q[1];
            int start = q[2];
            int x     = q[3];

            // Persistent update
            update(1, 0, n - 1, idx, value);

            // After removing nums[0 .. start-1],
            // count prefixes of nums[start .. n-1].
            Node res = query(1, 0, n - 1, start, n - 1);

            ans.push_back((int)res.cnt[x]);
        }

        return ans;
    }
};