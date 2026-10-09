class Solution {
public:
    int minInsertions(string s) {
        int open = 0;
        int ans = 0;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                open++;

                // The previous ')' pair was incomplete.
                // This case is handled when processing ')'
                // by checking whether open is zero.
            } 
            else {
                // If the next character is ')',
                // use both closing parentheses.
                if (i + 1 < s.size() && s[i + 1] == ')') {
                    i++;
                } 
                else {
                    // Insert one ')' to complete the pair.
                    ans++;
                }

                // Match the closing pair with an opening '('.
                if (open > 0) {
                    open--;
                } 
                else {
                    // Insert a missing '('.
                    ans++;
                }
            }
        }

        // Every remaining '(' requires two ')'.
        ans += 2 * open;

        return ans;
    }
};