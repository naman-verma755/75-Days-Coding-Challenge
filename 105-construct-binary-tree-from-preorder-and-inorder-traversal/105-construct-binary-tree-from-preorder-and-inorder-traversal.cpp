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
    TreeNode *build(int inStart, int inEnd, int preStart, int preEnd, vector<int>& inorder, vector<int>& preorder, map<int, int>&mp) {
        if(inStart > inEnd || preStart > preEnd)
            return NULL;
        
        int val = preorder[preStart];
        TreeNode *node = new TreeNode(val);
        int pos = mp[val];
        int dist = pos-inStart;
        
        node->left = build(inStart, pos-1, preStart+1, preStart+dist,  inorder, preorder, mp);
        node->right = build(pos+1, inEnd, preStart+dist+1, preEnd,  inorder, preorder, mp);
        return node;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
        map<int, int>mp;
        int n = preorder.size();
        for(int i = 0; i < n; i++) 
            mp[inorder[i]] = i;
        return build(0, n-1, 0, n-1, inorder, preorder, mp );
    }
};