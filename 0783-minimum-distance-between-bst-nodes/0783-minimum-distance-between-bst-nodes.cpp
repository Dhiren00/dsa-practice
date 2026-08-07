class Solution {
public:

    void sam(TreeNode *root, vector<int> &ans)
    {
        if(root == NULL)
            return;

        ans.push_back(root->val);
        sam(root->left, ans);
        sam(root->right, ans);
    }

    int minDiffInBST(TreeNode* root) {

        vector<int> ans;
        sam(root, ans);

        sort(ans.begin(), ans.end());

        int mini = INT_MAX;

        for(int i = 1; i < ans.size(); i++)
        {
            mini = min(mini, ans[i] - ans[i-1]);
        }

        return mini;
    }
};