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
    int findMaxHeight(TreeNode* root) {
        if(root == NULL)
            return 0;
        int left = findMaxHeight(root->left)+1;
        int right = findMaxHeight(root->right)+1;
        return max(left, right);
    }
    int maxDepth(TreeNode* root) {
        if(root == NULL)
            return 0;
        return findMaxHeight(root);
    }
};