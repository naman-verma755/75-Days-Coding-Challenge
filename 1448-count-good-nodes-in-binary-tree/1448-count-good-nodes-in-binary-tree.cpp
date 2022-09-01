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
    void dfs(TreeNode *node, int prev, int &count) {
        if(node == NULL)
            return;
        
        if(node->val >= prev)
            count++;
        
        dfs(node->left, max(prev, node->val), count);
        dfs(node->right, max(prev, node->val), count);
    }
    int goodNodes(TreeNode* root) {
        int count = 0;
        
        dfs(root, root->val, count);
        
        return count;
    }
};