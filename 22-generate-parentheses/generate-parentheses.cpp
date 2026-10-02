class Solution {
public:
    bool isValid(string s) {
        int open = 0;

        for(char ch : s) {
            if(ch == '(') {
                open++;
            }

            else {
                if(open == 0) {
                    return false;
                }

                open--;
            }
        }

        return (open == 0);
    }

    void solve(int n, string s, vector<string>& ans) {
        if(s.size() == 2*n) {
            if(isValid(s)) {
                ans.push_back(s);
            }

            return;
        }
        
        solve(n, s + '(', ans);
        solve(n, s + ')', ans);  
    }
    
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        solve(n, "", ans);
        return ans;
    }
};