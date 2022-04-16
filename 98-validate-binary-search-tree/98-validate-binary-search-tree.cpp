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
    bool check(TreeNode* root, long long mini, long long maxi) {
        
        if(root == NULL)
            return true;
        
        if(mini < root->val && root->val < maxi) {
            
            return check(root->left, mini, root->val) && check(root->right, root->val, maxi);
        }
        else
            return false;
    }
    bool isValidBST(TreeNode* root) {
        long long maxi = pow(2,31);
        long long mini = -1*pow(2,31)-1;
        return check(root, mini, maxi);
    }
};