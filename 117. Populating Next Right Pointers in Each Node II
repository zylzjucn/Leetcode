/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if (!root)
            return;
        queue<TreeLinkNode*> q;
        TreeLinkNode* p;
        q.push(root);
        q.push(NULL);
        while (!q.empty()) {
            if (q.front()) {
                p = q.front();
                if (p->left)
                    q.push(p->left);
                if (p->right)
                    q.push(p->right);
                q.pop();
                p->next = q.front();
            }
            else {
                q.pop();
                if (!q.empty())
                    q.push(NULL);
            }
        }
    }
};
