class Solution {
public:
    int arrangeCoins(int n) {
        int coins = n;

        for(int i = 1; i <= n; i++) {
            if(coins < i) {
                return i - 1;
            }

            coins -= i;
        }

        return 1;
    }
};