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
    void insert(TreeNode * root, int val, TreeNode *prev, char ch) {
        
        if(root == NULL) {
            TreeNode *node = new TreeNode(val);
            if(ch == 'l')
                prev->left = node;
            else 
                prev->right = node;
            return;
        }
        
        if(val < root->val) 
            insert(root->left, val, root, 'l');
        else
            insert(root->right, val, root, 'r');
    }
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        
        if(root == NULL)
            return new TreeNode(val);
        insert(root, val, NULL, 'l');
        return root;
    }
};