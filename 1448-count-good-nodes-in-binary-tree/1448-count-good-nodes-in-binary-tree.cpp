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
    int goodNodes(TreeNode* root) {
        
        int count = 0;
        queue<pair<TreeNode*,int>>q;
        q.push({root, -10003});
        
        while(!q.empty()) {
            int size = q.size();
            while(size > 0) {
                
                pair<TreeNode*, int> it = q.front();
                q.pop();
                if(it.first->val >= it.second)
                    count++;
                int maxi = max(it.first->val, it.second);
                if(it.first->left != NULL)
                    q.push({it.first->left, maxi});
                if(it.first->right != NULL)
                    q.push({it.first->right, maxi});
                
                size--;
            }
        }
        return count;
        
    }
};