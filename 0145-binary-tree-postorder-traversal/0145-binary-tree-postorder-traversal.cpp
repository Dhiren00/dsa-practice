class Solution {
public:
    void os(TreeNode* root, vector<int>& ans)
    {
        if (root == NULL)
            return;

        os(root->left, ans);
        os(root->right, ans);
        ans.push_back(root->val);
    }

    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        os(root, ans);
        return ans;
    }
};