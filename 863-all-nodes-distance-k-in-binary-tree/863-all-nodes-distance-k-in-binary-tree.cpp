/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void traverse(TreeNode* prev, TreeNode* root, map<TreeNode*, TreeNode*>&mp) {
        
        if(root == NULL)
            return;
        
        if(prev != NULL)
            mp[root] = prev;
        
        traverse(root, root->left, mp);
        traverse(root, root->right, mp);
        
        
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        map<TreeNode*, TreeNode*>mp;
        
        traverse(NULL, root, mp);
        // for(auto it = mp.begin(); it!= mp.end(); it++)
        // cout<<it->first->val<<" "<<it->second->val<<endl;
        // cout<<target->left->val;
        vector<int>ans;
            
        queue<pair<TreeNode*, int>>q;
        q.push({target, k});
        map<TreeNode*, int>visited;
        while(!q.empty()) {
            int size = q.size();
            while(size > 0) {
                pair<TreeNode*, int> it = q.front();
                q.pop();
                TreeNode *node = it.first;
                
                
                if(!visited.count(node))
                    visited[node] ++;
                else
                {
                    size--;
                    continue;
                }
                if(it.second == 0)
                {
                    ans.push_back(node->val);
                    size--;
                continue;
                }
                if(it.second < 0)continue;
                if(node->left != NULL)
                q.push({node->left, it.second-1});
                if(node->right != NULL)
                    q.push({node->right, it.second-1});
                if(mp.count(node))
                     q.push({mp[node],it.second-1});
                size--;
            }
            
        }
        
            
        return ans;
        
    }
};