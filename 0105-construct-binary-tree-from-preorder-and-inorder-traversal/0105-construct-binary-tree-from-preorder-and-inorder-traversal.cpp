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
    int search(vector<int>& inorder, int p) {
        for (int i = 0; i < inorder.size(); i++) {
            if (inorder[i] == p) {
                return i;
            }
        }
        return -1;
    }

    TreeNode* helper(vector<int>& preorder, vector<int>& inorder,
                     int& preIndex, int left, int right) {

        if (left > right) {
            return NULL;
        }

        TreeNode* node = new TreeNode(preorder[preIndex]);

        int index = search(inorder, preorder[preIndex]);
        preIndex++;

        node->left = helper(preorder, inorder, preIndex, left, index - 1);
        node->right = helper(preorder, inorder, preIndex, index + 1, right);

        return node;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int preIndex = 0;
        return helper(preorder, inorder, preIndex, 0, inorder.size() - 1);
    }
};