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
    bool isEvenOddTree(TreeNode* root) {
        
        
        int flag = 0;
        
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()) {
            int prev;
            if(flag == 0)
             prev = 0;
            else
                prev = INT_MAX;
            int size = q.size();
            while(size > 0) {
                
                TreeNode *node = q.front();
            
                if(flag == 0 && (prev >= node->val || !(node->val & 1))) 
                    return false;
                if(flag == 1 && (prev <= node->val || (node->val & 1)))
                    return false;
                prev = node->val;
                q.pop();
                if(node->left != NULL)
                    q.push(node->left);
                if(node->right != NULL)
                    q.push(node->right);
                size--;
            }
           flag = !flag;
            
        }
        
        return true;
    }
};