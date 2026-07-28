class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

        // Base case
        if (root == NULL) {
            return NULL;
        }

        // If root is either p or q, root is the LCA
        if (root->val == p->val || root->val == q->val) {
            return root;
        }

        // Search in left and right subtrees
        TreeNode* leftLCA = lowestCommonAncestor(root->left, p, q);
        TreeNode* rightLCA = lowestCommonAncestor(root->right, p, q);

        // If p and q are found in different subtrees
        if (leftLCA && rightLCA) {
            return root;
        }

        // If found only in left subtree
        else if (leftLCA != NULL) {
            return leftLCA;
        }

        // If found only in right subtree
        else {
            return rightLCA;
        }
    }
};