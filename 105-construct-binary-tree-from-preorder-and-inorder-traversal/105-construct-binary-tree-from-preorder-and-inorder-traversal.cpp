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
TreeNode* build(vector<int>&preorder, vector<int>&inorder, int preStart, int preEnd, int inStart, int inEnd, map<int, int>&mp)  {
        
     if(preStart > preEnd || inStart > inEnd)
         return NULL;
         
      TreeNode* root = new TreeNode(preorder[preStart]);
      int inRoot = mp[preorder[preStart]];
      int temp = inRoot-inStart;
      root->left = build(preorder, inorder, preStart+1, preStart+temp, inStart, inRoot-1, mp);
      root->right = build(preorder, inorder, preStart+temp+1, preEnd, inRoot+1, inEnd, mp);
      return root;
          
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int preStart = 0, preEnd = preorder.size();
        int inStart = 0, inEnd = inorder.size();
        map<int, int>mp;
        for(int i = 0; i < inEnd; i++) 
            mp[inorder[i]] = i;
        
        TreeNode *root = build(preorder, inorder, preStart, preEnd-1, inStart, inEnd-1, mp);
        return root;
    }
};