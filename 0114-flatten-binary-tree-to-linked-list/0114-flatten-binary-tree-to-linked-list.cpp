class Solution {
public:
    TreeNode* nr = NULL;

    void flatten(TreeNode* root) {
        if (root == NULL)
            return;

        flatten(root->right);
        flatten(root->left);

        root->left = NULL;
        root->right = nr;
        nr = root;
    }
};