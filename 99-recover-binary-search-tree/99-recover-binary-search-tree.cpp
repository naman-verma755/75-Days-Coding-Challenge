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
            TreeNode *first = NULL, *second = NULL, *third=NULL, *prev = NULL;

    void findSwappedNodes(TreeNode *root) {
        
        if(root == NULL)
            return;
        
        findSwappedNodes(root->left);
        
        if(prev != NULL && prev->val > root->val) {
            // cout<<prev->val;
            
            if(first == NULL)
            {
                 // cout<<prev->val;
                first = prev;
                // cout<<first->val;
                second = root;
            }
            else
            {
                third = root;
            }
        }
        prev = root;
        findSwappedNodes(root->right);
    } 
public:
    void recoverTree(TreeNode* root) {
        
        // TreeNode *first = NULL, *second = NULL, *third=NULL, *prev = NULL;
        findSwappedNodes(root);
        // cout<<third->val;
        if(third != NULL)
        {
            int k = third->val;
            third->val = first->val;
            first->val = k;
        }
        else
        {
            int k = first->val;
            first->val = second->val;
            second->val = k;
        }
        
        
    }
};