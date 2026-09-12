class Solution {
public:
    struct Node {
        long long score;
        vector<int> indices;
    };

    bool better(Node &a, Node &b) {
        if (a.score != b.score)
            return a.score > b.score;

        return a.indices < b.indices;
    }

    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        int n = intervals.size();

        // {start, end, score, original index}
        vector<array<int, 4>> a;

        for (int i = 0; i < n; i++) {
            a.push_back({
                intervals[i][0],
                intervals[i][1],
                intervals[i][2],
                i
            });
        }

        // Sort by end time
        sort(a.begin(), a.end(), [](auto &x, auto &y) {
            if (x[1] != y[1])
                return x[1] < y[1];

            return x[0] < y[0];
        });

        // Find previous non-overlapping interval
        vector<int> prev(n, -1);

        for (int i = 0; i < n; i++) {

            int low = 0;
            int high = i - 1;

            while (low <= high) {

                int mid = low + (high - low) / 2;

                if (a[mid][1] < a[i][0]) {
                    prev[i] = mid;
                    low = mid + 1;
                }
                else {
                    high = mid - 1;
                }
            }
        }

        // dp[i][k] = best answer using first i intervals
        // with at most k intervals
        vector<vector<Node>> dp(
            n + 1,
            vector<Node>(5)
        );

        for (int i = 1; i <= n; i++) {

            for (int k = 1; k <= 4; k++) {

                // Don't take current interval
                Node notTake = dp[i - 1][k];

                // Take current interval
                Node take;

                take.score = a[i - 1][2];

                int p = prev[i - 1];

                if (p != -1) {
                    take.score += dp[p + 1][k - 1].score;
                    take.indices = dp[p + 1][k - 1].indices;
                }

                take.indices.push_back(a[i - 1][3]);

                sort(take.indices.begin(), take.indices.end());

                if (better(take, notTake))
                    dp[i][k] = take;
                else
                    dp[i][k] = notTake;
            }
        }

        return dp[n][4].indices;
    }
};