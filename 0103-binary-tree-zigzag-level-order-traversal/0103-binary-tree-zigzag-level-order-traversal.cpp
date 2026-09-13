class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        
        vector<vector<int>> ans;

        if (root == nullptr)
            return ans;

        queue<TreeNode*> q;
        q.push(root);

        bool leftToRight = true;

        while (!q.empty()) {

            int n = q.size();
            vector<int> level(n);

            for (int i = 0; i < n; i++) {

                TreeNode* node = q.front();
                q.pop();

                // Decide where to put the current node
                int index;

                if (leftToRight)
                    index = i;
                else
                    index = n - 1 - i;

                level[index] = node->val;

                // Add children to queue
                if (node->left != nullptr)
                    q.push(node->left);

                if (node->right != nullptr)
                    q.push(node->right);
            }

            ans.push_back(level);

            // Change direction
            leftToRight = !leftToRight;
        }

        return ans;
    }
};