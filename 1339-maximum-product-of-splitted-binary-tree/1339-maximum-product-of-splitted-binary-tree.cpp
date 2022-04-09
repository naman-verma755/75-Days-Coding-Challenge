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
    long long findSum(TreeNode *root) {
        
        if(root == NULL)
            return 0;
        
        int leftSum = findSum(root->left);
        int rightSum = findSum(root->right);
        return (root->val+leftSum+rightSum);
    }
    long long findActualAns(TreeNode *root, long long &maxi, long long &totalSum) {
        
        if(root == NULL)
            return 0;
        
        long long leftSum = findActualAns(root->left, maxi, totalSum);
        long long rightSum = findActualAns(root->right, maxi, totalSum);
        long long currSum = (root->val+leftSum+rightSum);
        maxi = max(maxi, (currSum * (totalSum-currSum)));
        return currSum;
    }
    int maxProduct(TreeNode* root) {
        
        long long maxi = 0;
        
        long long totalSum = findSum(root);
        
        int temp = findActualAns(root, maxi, totalSum);
        return (maxi%1000000007);
        
    }
};