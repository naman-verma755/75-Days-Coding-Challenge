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
        long long maxi = 0;
        while(!q.empty()) {
            int size = q.size();
            long long leftMost = q.front().second;
            
            while(size > 0) {
                
                TreeNode* node = q.front().first;
                long long level = q.front().second;
                q.pop();
                long long k = level-leftMost;
                if(node->left != NULL) {
                    q.push({node->left, (2*k+1)});
                }
                if(node->right != NULL) {
                    q.push({node->right, (2*k+2)});
                }
                maxi = max(maxi, (level-leftMost+1));
                size--;
            }
        }
        return maxi;
    }
};