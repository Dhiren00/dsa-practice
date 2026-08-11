class Solution {
public:
    TreeNode* previous = NULL;
    TreeNode* first = NULL;
    TreeNode* second = NULL;

    void inorder(TreeNode* root) {
        if (root == NULL) {
            return;
        }

        // Left
        inorder(root->left);

        // Current
        if (previous != NULL && root->val < previous->val) {
            if (first == NULL) {
                first = previous;
            }

            second = root;
        }

        previous = root;

        // Right
        inorder(root->right);
    }

    void recoverTree(TreeNode* root) {
        inorder(root);

        swap(first->val, second->val);
    }
};