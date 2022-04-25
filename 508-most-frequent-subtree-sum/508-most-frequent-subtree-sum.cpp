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
    int findSum(TreeNode *root, map<int, int>&mp) {
        
        if(root == NULL)
            return 0;
         int left = 0, right = 0;
        if(root->left != NULL)
            left = findSum(root->left, mp);
        
        if(root->right != NULL)
            right = findSum(root->right, mp);
        
        int sum = root->val+left+right;
        mp[sum] ++;
        return sum;
    }
    vector<int> findFrequentTreeSum(TreeNode* root) {
        
        map<int, int>mp;
        
        int k = findSum(root, mp);
        // mp[k] ++;
        int maxi = 0;
        for(auto it : mp) {
            maxi = max(it.second, maxi);
        }
        vector<int>ans;
        for(auto it : mp) {
            if(maxi == it.second)
                ans.push_back(it.first);
        }
        return ans;
    }
};