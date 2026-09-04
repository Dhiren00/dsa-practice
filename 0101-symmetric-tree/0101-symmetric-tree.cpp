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

    bool ans(TreeNode* left, TreeNode* right)
    {
        // Both are empty
        if(left == NULL && right == NULL)
            return true;

        // One is empty, other isn't
        if(left == NULL || right == NULL)
            return false;

        // Values are different
        if(left->val != right->val)
            return false;

        // Check mirror pairs
        return ans(left->left, right->right) &&
               ans(left->right, right->left);
    }

    bool isSymmetric(TreeNode* root)
    {
        if(root == NULL)
            return true;

        return ans(root->left, root->right);
    }
};