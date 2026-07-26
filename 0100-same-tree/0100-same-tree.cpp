class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {

        if (p == NULL || q == NULL) {
            return p == q;
        }

        bool leftissame = isSameTree(p->left, q->left);
        bool rightissame = isSameTree(p->right, q->right);

        return leftissame && rightissame && (p->val == q->val);
    }
};