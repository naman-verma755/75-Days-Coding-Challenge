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
    int func(TreeNode *root, int k) {
        
        if(root == NULL)
            return 0;
        
        int right = func(root->right, k);
        
        int nodeVal = root->val;
        root->val = root->val+right+k;
        int left = func(root->left, root->val);
        return right+nodeVal+left;
    }
    TreeNode* convertBST(TreeNode* root) {
        
        int sum = func(root, 0);
        return root;
        
    }
};