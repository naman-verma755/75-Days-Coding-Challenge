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
    void findPaths(TreeNode* root, int targetSum, long long currSum, map<long long, long long>&mp, int &count) {
        if(root == NULL)
            return;
        
        // if(root->val == targetSum)
        //     count ++;
        // if(currSum == targetSum)
        //     count++;
        currSum += root->val;
        if(mp.count(currSum-targetSum))
            count+= mp[currSum-targetSum];
        
        mp[currSum]++;
        findPaths(root->left, targetSum, currSum, mp, count);
        findPaths(root->right, targetSum, currSum, mp, count);
        mp[currSum]--;
        
    }
    int pathSum(TreeNode* root, int targetSum) {
        
        map<long long, long long>mp;
        int count = 0;
        mp[0] = 1;
        findPaths(root, targetSum, 0, mp, count);
        return count;
        
        
    }
};