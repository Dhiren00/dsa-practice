class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        queue<TreeNode*> q;
        vector<double> ans1;

        if (!root)
            return {};

        q.push(root);

        while (!q.empty()) {
            int nodes = q.size();
            long long sum = 0;

            for (int j = 0; j < nodes; j++) {
                TreeNode* temp = q.front();
                q.pop();

                sum += temp->val;

                if (temp->left)
                    q.push(temp->left);

                if (temp->right)
                    q.push(temp->right);
            }

            ans1.push_back((double)sum / nodes);
        }

        return ans1;
    }
};