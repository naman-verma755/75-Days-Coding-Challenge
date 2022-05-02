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
    bool find(TreeNode *root, int depth, int x, int y, int &depth1,int &depth2) {
        
        if(root == NULL)
            return false;
        if(root->val == x || root->val == y) {
            if(depth1 == -1)
                depth1 = depth;
            else
                depth2 = depth;
        }
        if(root->left != NULL && root->right != NULL)
        {
            if((root->left->val == x && root->right->val == y)||(root->left->val == y && root->right->val == x))
                return true;
        }
        
        
        bool l = find(root->left, depth+1, x, y, depth1, depth2);
        bool r = find(root->right, depth+1, x, y, depth1, depth2);
        if(l || r)
            return true;
        return false;
        
        
    }
    bool isCousins(TreeNode* root, int x, int y) {
        
       
        
        int depthx = -1, depthy = -1;
        
       bool isSame = find(root, 0, x, y, depthx, depthy);
        if(isSame)
            return false;
        
        if(depthx == depthy)
            return true;
        
        return false;
    }
};