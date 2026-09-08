class Solution {
public:
    int countCommas(int n) {
        int ans = n - 999;

        if(ans >= 0) {
            return ans;
        }

        return 0;
    }
};