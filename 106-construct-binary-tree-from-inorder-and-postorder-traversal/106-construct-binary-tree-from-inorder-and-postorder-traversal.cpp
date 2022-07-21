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
    int search(int i, int n, vector<int>& inorder, int ele) {
        
        while(i <= n) {
            if(inorder[i] == ele) return i;
            i++;
        }
        return 0;
    }
    TreeNode* build(int lleft, int lright, int rleft, int rright, vector<int>& inorder, vector<int>& postorder) {
        
        if(lleft>lright  || rleft > rright)
            return NULL;
        
        TreeNode *node = new TreeNode(postorder[rright]);
        int pos = search(lleft, lright, inorder, postorder[rright]);
        int dist = lright-pos;
        node->left = build(lleft, pos-1, rleft, rright-dist-1, inorder, postorder);
        
        node->right = build(pos+1, lright, rright-dist, rright-1, inorder, postorder);
        
        return node;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        return build(0, n-1, 0, n-1, inorder, postorder);
    }
};