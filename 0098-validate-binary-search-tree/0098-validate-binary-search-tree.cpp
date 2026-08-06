class Solution {
public:
    bool kyaye(TreeNode* root, TreeNode* min, TreeNode* max) {

        if (root == NULL)
            return true;

        if (min != NULL && root->val <= min->val)
            return false;

        if (max != NULL && root->val >= max->val)
            return false;

        return kyaye(root->left, min, root) &&
               kyaye(root->right, root, max);
    }

    bool isValidBST(TreeNode* root) {
        return kyaye(root, NULL, NULL);
    }
};