class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long> ans(k, 0);
        vector<long long> prevCount(k, 0);

        for(int i = 0; i < n; i++) {
            vector<long long> currCount(k, 0);
            currCount[nums[i] % k]++;

            for(int oldRem = 0; oldRem < k; oldRem++) {
                int newRem = ((long long)oldRem * nums[i] % k) % k;

                currCount[newRem] += prevCount[oldRem];
            }

            prevCount = move(currCount);

            for(int x = 0; x < k; x++) {
                ans[x] += prevCount[x];
            }
        }

        return ans;
    }
};