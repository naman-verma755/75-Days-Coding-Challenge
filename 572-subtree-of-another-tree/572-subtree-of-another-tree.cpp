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
    bool check(TreeNode *T, TreeNode *S) {
        
        if(T == NULL && S == NULL)
        return true;
        if(T == NULL || S == NULL)
        return false;
        
        if(T->val == S->val) {
            bool left = check(T->left, S->left);
            bool right = check(T->right, S->right);
            if(left == false || right == false)
            return false;
            else
            return true;
        }
        else
        return false;
    }
    bool func(TreeNode *T, TreeNode *S) {
        
        if(T == NULL)
        return false;
        
        if(T->val == S->val)
        {
            bool f = check(T,S);
            if(f)
                return true;
        }
        
        bool left = func(T->left, S);
        bool right = func(T->right, S);
        if(left || right)
        return true;
        
        return false;
    }
    bool isSubtree(TreeNode* T,TreeNode* S) 
    {
        // Your code here
        return func(T, S);
        
    }
//     bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        
//     }
};