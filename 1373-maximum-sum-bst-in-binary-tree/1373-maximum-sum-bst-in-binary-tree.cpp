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

struct NodeVal {
    int mini;
    int maxi;
    int sum;
    
    NodeVal(int _mini, int _maxi, int _sum) {
        mini = _mini;
        maxi = _maxi;
        sum = _sum;
    }
};
class Solution {
public:
    NodeVal* findSum(TreeNode *root, int &max_sum) {
        
        if(root == NULL)
            return new NodeVal(INT_MAX, INT_MIN, 0);
        
        auto left = findSum(root->left, max_sum);
        auto right = findSum(root->right, max_sum);
        // cout<<root->val<<" ";
        // cout<<left->sum<<" "<<right->sum<<" ";
        // cout<<endl;
        if(left->maxi < root->val && root->val < right->mini) {
            max_sum = max(max_sum,(right->sum+left->sum+root->val));
            return new NodeVal(min(root->val, left->mini), max(root->val, right->maxi), (right->sum+left->sum+root->val));
        }
        return new NodeVal(INT_MIN, INT_MAX, max(left->sum, right->sum));
    }
    int maxSumBST(TreeNode* root) {
        int max_sum = 0;
        auto ans = findSum(root, max_sum);
      
        return max_sum;
        
    }
};