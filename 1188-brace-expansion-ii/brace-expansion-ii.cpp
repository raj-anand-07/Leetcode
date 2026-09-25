class Solution {
public:
    string s;
    int i = 0;

    set<string> parse() {
        set<string> result;
        set<string> cur = {""};

        while (i < s.size() && s[i] != '}') {

            if (s[i] == ',') {
                // Union
                result.insert(cur.begin(), cur.end());
                cur = {""};
                i++;
            }

            else if (s[i] == '{') {
                i++; // skip '{'

                set<string> nested = parse();

                i++; // skip '}'

                // Concatenation
                set<string> temp;

                for (string a : cur) {
                    for (string b : nested) {
                        temp.insert(a + b);
                    }
                }

                cur = temp;
            }

            else {
                // Normal character
                char ch = s[i];
                i++;

                set<string> temp;

                for (string str : cur) {
                    temp.insert(str + ch);
                }

                cur = temp;
            }
        }

        // Add the last concatenation part
        result.insert(cur.begin(), cur.end());

        return result;
    }

    vector<string> braceExpansionII(string expression) {
        s = expression;
        i = 0;

        set<string> ans = parse();

        return vector<string>(ans.begin(), ans.end());
    }
};