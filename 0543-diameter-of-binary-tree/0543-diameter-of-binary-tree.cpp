class Solution {
public:
    int height(TreeNode* root)
    {
        if (root == NULL)
            return 0;

        int leftmax = height(root->left);
        int rightmax = height(root->right);

        return max(leftmax, rightmax) + 1;
    }

    int diameterOfBinaryTree(TreeNode* root)
    {
        if (root == NULL)
            return 0;

        int leftmax = diameterOfBinaryTree(root->left);
        int rightmax = diameterOfBinaryTree(root->right);

        int currentdia = height(root->left) + height(root->right);

        return max(max(leftmax, rightmax), currentdia);
    }
};