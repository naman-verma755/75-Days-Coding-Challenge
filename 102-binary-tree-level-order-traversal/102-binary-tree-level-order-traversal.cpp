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
    vector<vector<int>> levelOrder(TreeNode* root) {
        
        vector<vector<int>>ans;
        if(root == NULL)
            return ans;
        queue<TreeNode*>qu;
        qu.push(root);
        while(!qu.empty()) {
            int size = qu.size();
            vector<int>subAns;
            while(size > 0) {
                TreeNode *node = qu.front();
                subAns.push_back(node->val);
                qu.pop();
                if(node->left != NULL)
                    qu.push(node->left);
                if(node->right != NULL)
                    qu.push(node->right);
                
                size--;
            }
            ans.push_back(subAns);
        }
        return ans;
        
    }
};