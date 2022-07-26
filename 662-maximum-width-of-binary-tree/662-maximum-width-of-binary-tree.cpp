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
    int widthOfBinaryTree(TreeNode* root) {
        
        queue<pair<TreeNode*, long long>>q;
        q.push({root, 0});
        int maxi = 0;
        while(!q.empty()) {
            
            int k = q.size();
            int leftMost = q.front().second;
            while(k > 0) {
                TreeNode *node = q.front().first;
               long long level = q.front().second;
                maxi = max(maxi,(int)(level-leftMost+1));
                q.pop();
                long long r = level-leftMost;
                if(node->left != NULL) 
                    q.push({node->left, (2*r+1)});
                if(node->right != NULL)
                    q.push({node->right, (2*r+2)});
                
                k--;
                
            }
        }
        return maxi;
    }
};