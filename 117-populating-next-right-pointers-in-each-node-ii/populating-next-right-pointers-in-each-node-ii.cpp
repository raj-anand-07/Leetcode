/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(root == NULL) {
            return root;
        }

        queue<Node*> que;
        que.push(root);

        while(!que.empty()) {
            int n = que.size();

            for(int i = 0; i < n; i++) {
                Node* temp = que.front();
                que.pop();

                if(i < n - 1) {
                    temp -> next = que.front();
                }

                if(temp -> left) {
                    que.push(temp -> left);
                }

                if(temp -> right) {
                    que.push(temp -> right);
                }
            }
        }

        return root;
    }
};