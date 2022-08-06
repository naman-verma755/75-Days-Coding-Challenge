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
    vector<int> rightSideView(TreeNode* root) {
        
        vector<int>ans;
        if(root == NULL)
            return ans;
        map<int, TreeNode*>mp;
    
        queue<pair<TreeNode*, int>>q;
        q.push({root, 0});
        
        while(!q.empty()) {
            int k = q.size();
            while(k > 0) {
                TreeNode *node = q.front().first;
                int level = q.front().second;
                q.pop();
                mp[level] = node;
                
                if(node->left != NULL)
                    q.push({node->left, level+1});
                
                if(node->right != NULL)
                   q.push({node->right, level+1});
                k--;
            }
        }
        for(auto it : mp)
            ans.push_back(it.second->val);
        return ans;
    }
};