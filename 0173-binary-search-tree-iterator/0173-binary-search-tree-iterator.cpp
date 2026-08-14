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
class BSTIterator {
public:
stack<TreeNode *>ans;
void helper(TreeNode *root)
{
    
    while(root!=NULL)
    {
        ans.push(root);
        root=root->left;
    }
}
    BSTIterator(TreeNode* root) {
        helper(root);


        
    }
    
    int next() {
        TreeNode *s=ans.top();
        ans.pop();
        if(s->right!=NULL)
        {
            helper(s->right);
        }

return s->val;
        
    }
    
    bool hasNext() {
        return ans.size()>0;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */