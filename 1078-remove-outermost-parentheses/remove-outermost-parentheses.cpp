class Solution {
public:
    string removeOuterParentheses(string s) {
        // int i = 0;
        // int leftcount = 0;
        // int leftIndex = 0;
        // while(i < s.length()) {
        //     if(s[i] == '(') {
        //         leftcount++;
        //     }
        //     else if(s[i] == ')') {
        //         leftcount--;
        //     }

        //     if(leftcount == 0) {
        //         s.erase(leftIndex, 1);
        //         s.erase(i-1, 1);
        //         i -= 2;
        //         leftIndex = i+1;
        //     }
        //     i++;
        // }
        // return s;

        // Approach 2
        // int i = 0;
        // long long leftCount = 0;
        // string ans = "";

        // while(i < s.length()) {
        //     if(s[i] == '(') leftCount++;
        //     else leftCount--;

        //     if(leftCount != 0 && leftCount != 1) {
        //         ans.push_back(s[i]);
        //         if(s[i+1] == ')' && leftCount == 2) {
        //             ans += ')';
        //             i++;
        //             leftCount--;
        //         }
        //     } 
        //     i++;
        // }
        // return ans;

        int open = 0;
        string ans = "";

        for(char ch : s) {
            if((ch == '(' && open > 0) || (ch == ')' && open > 1)) {
                ans.push_back(ch);
            }

            if(ch == '(') {
                open++;
            }

            else {
                open--;
            }  
        }

        return ans;
    }
};