class Solution {
public:
    int reverseDegree(string s) {
        int len = s.size();
        long long ans = 0;

        for(int i = 0; i < len; i++) {
            int rev = 'a' - s[i] + 26;
            ans += rev * (i + 1);
        }

        return ans;
    }
};