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
    int func(TreeNode *root, int &maxi) {
        
        if(root == NULL)
            return -1004;
        
        int left = func(root->left, maxi);
        int right = func(root->right, maxi);
        
        maxi = max(maxi, root->val);
        int k = max(root->val+left+right, max(root->val+left, root->val+right));
        maxi = max(maxi, k);
        
        return max(root->val,root->val+max(left,right));
    }
    int maxPathSum(TreeNode* root) {
        
        int maxi = INT_MIN;
        int k = func(root, maxi);
        return maxi;
    }
};