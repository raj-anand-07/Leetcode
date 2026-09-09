class Solution {
public:
    long long countCommas(long long n) {
        long long ans = 0;

        if(n < 1000) {
            return ans;
        }

        else if(n < 1e6) {
            ans += (n - 999);
        }

        else if(n < 1e9) {
            ans += (n - 999);
            ans += (n - 999999);
        }

        else if(n < 1e12) {
            ans += (n - 999);
            ans += (n - 999999);
            ans += (n - 999999999);
        }

        else if(n < 1e15) {
            ans += (n - 999);
            ans += (n - 999999);
            ans += (n - 999999999);
            ans += (n - 999999999999);
        }

        else {
            ans += (n - 999);
            ans += (n - 999999);
            ans += (n - 999999999);
            ans += (n - 999999999999);
            ans += (n - 999999999999999);
        }

        return ans;
    }
};