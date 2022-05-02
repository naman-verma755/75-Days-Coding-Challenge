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
    int findMaxSum(TreeNode *root, int &maxSum) {
        
        if(root == NULL)
            return 0;
        
        int leftSum = findMaxSum(root->left, maxSum);
        int rightSum = findMaxSum(root->right, maxSum);
        
        maxSum = max(maxSum, max(root->val+leftSum+rightSum, max(root->val+leftSum, root->val+rightSum)));
        maxSum = max(maxSum, root->val);
        
        return max(root->val,  max(root->val+leftSum, root->val+rightSum));
    }
    int maxPathSum(TreeNode* root) {
      
        int maxSum = INT_MIN;
        
        
        int resultant = findMaxSum(root, maxSum);
        return maxSum;
    }
};