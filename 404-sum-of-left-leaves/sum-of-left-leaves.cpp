/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void solve(TreeNode* root, bool left, int& ans) {
        if(root -> left == NULL && root -> right == NULL) {
            if(left) {
                ans += root -> val;
            }
        }

        if(root -> left) {
            solve(root -> left, true, ans);
        }

        if(root -> right) {
            solve(root -> right, false, ans);
        }
    }

    int sumOfLeftLeaves(TreeNode* root) {
        int ans = 0;
        solve(root, false, ans);

        return ans;
    }
};