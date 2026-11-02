class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n = nums.size();
        long long ans = INT_MAX;

        for(int i = 0; i < n; i++) {
            long long diff = 0;

            for(int j = 0; j < n; j++) {
                diff += abs(nums[i] - nums[j]);
            }

            ans = min(ans, diff);
        }

        return ans;
    }
};