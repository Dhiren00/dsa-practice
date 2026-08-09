class Solution {
public:
    void smalldih(TreeNode* root, vector<int>& ans)
    {
        if (root == NULL)
        {
            return;
        }

        ans.push_back(root->val);

        smalldih(root->left, ans);
        smalldih(root->right, ans);
    }

    int kthSmallest(TreeNode* root, int k) {
        vector<int> ans;

        smalldih(root, ans);

        sort(ans.begin(), ans.end());

        return ans[k - 1];
    }
};