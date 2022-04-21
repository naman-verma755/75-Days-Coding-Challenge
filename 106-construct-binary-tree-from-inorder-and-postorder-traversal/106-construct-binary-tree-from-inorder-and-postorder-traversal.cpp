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
    TreeNode* build(vector<int>& postorder, vector<int>&inorder, int postStart, int postEnd, int inStart, int inEnd, map<int, int>&mp) {
        
        if(postStart > postEnd || inStart > inEnd)
            return NULL;
        int val = postorder[postEnd];
        // cout<<val<<" ";
        TreeNode* root = new TreeNode(val);
        
        int inRoot = mp[val];
        int temp = inRoot-inStart;
        
        root->left = build(postorder, inorder, postStart, postStart+temp-1, inStart, inRoot-1, mp);
        root->right = build(postorder, inorder, postStart+temp, postEnd-1, inRoot+1, inEnd, mp);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        
        map<int, int>mp;
        for(int i = 0; i < inorder.size(); i++) {
            mp[inorder[i]] = i;
        }
        TreeNode* root = build(postorder, inorder, 0, postorder.size()-1, 0, inorder.size()-1, mp);
        return root;
    }
};