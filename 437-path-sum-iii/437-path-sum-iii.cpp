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
    void findPathSum(TreeNode *root, long long sum, int targetSum, int &count, map<long long, int>&mp) {
        
        if(root == NULL)
            return;
        
        sum += root->val;
        // cout<<sum<<" ";
        if(mp.count(sum-targetSum) ) 
            count += mp[sum-targetSum];
        if(sum == targetSum)
            count++;
            
        mp[sum] ++;
        
        findPathSum(root->left, sum, targetSum, count, mp);
        findPathSum(root->right, sum, targetSum, count, mp);
            
        mp[sum]--;
        
        
    }
    int pathSum(TreeNode* root, int targetSum) {
        
        map<long long, int>mp;
        
        int count = 0;
        findPathSum(root, 0, targetSum, count, mp);
            
        return count;
               
    }
};