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
    
    int buildGST(TreeNode *root, int rightNodesSum) {
        
        if(root == NULL)
            return 0;
        
        int rightSum = buildGST(root->right, rightNodesSum);
        
        int nodeVal = root->val;
        root->val = root->val + rightNodesSum + rightSum;
        int leftSum = buildGST(root->left, root->val);
        
        return rightSum+nodeVal+leftSum;
    }
    TreeNode* bstToGst(TreeNode* root) {
        
        
        
        int loc = buildGST(root, 0);
        
        return root;
        
        
        
    }
};