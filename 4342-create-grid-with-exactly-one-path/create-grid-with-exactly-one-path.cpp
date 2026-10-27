class Solution {
public:
    vector<string> createGrid(int m, int n) {
        vector<vector<char>> path(m, vector<char>(n, '#'));

        int i = 0, j = 0;

        while(i < m && j < n) {
            path[i][j] = '.';
            
            if(j == n - 1) {
                i++;
            }
            else {
                j++;
            }
        }

        vector<string> ans;

        for(int i = 0; i < m; i++) {
            string s = "";

            for(int j = 0; j < n; j++) {
                s += path[i][j];
            }

            ans.push_back(s);
        }

        return ans;
    }
};