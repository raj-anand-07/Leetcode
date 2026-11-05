class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        long long ans = INT_MIN;

        for(int i = 0; i < n; i++) {
            long long prod = 1;

            for(int j = i; j < n; j++) {
                prod *= nums[j];
                ans = max(ans, prod);
            }
        }

        return ans;
    }
};