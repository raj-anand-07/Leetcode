class Solution {
public:
    bool isValid(string s) {
        stack<char> st;

        for(char ch : s) {
            // ch is opening bracket
            if(ch == '(' || ch == '{' || ch == '[') {
                st.push(ch);
            }

            // ch is closing bracket
            else {
                if(st.empty()) {
                    return false;
                }

                if((ch == ')' && st.top() != '(') ||
                   (ch == '}' && st.top() != '{') ||
                   (ch == ']' && st.top() != '[')) {
                    return false;
                }

                st.pop();
            }
        }

        return st.empty();
    }
};