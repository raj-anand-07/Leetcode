class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        if (sum > 9 * num) {
            return "";
        }

        string ans = "";

        while (sum > 0 && num > 0) {
            int digit = min(9, sum);
            ans += char('0' + digit);

            sum -= digit;
            num--;
        }

        ans += string(num, '0');

        return ans;
    }
};