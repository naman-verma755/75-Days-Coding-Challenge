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
//     bool isValid(int index, int prev, TreeNode *node) {
        
//         if(index&1) {
//             if(prev > node->val)
//                 return true;
//             else
//                 return false;
//         }
//          if(!(index&1)) {
//             if(prev < node->val)
//                 return true;
//             else
//                 return false;
//         }
//         return true;
//     }
    bool isEvenOddTree(TreeNode* root) {
        
        
        queue<TreeNode*>q;
        q.push(root);
        bool flag = false;
        while(!q.empty()) {
            
            int k = q.size();
            int prev = (!flag)?INT_MIN:INT_MAX;
            while(k > 0) {
                // cout<<prev<<" "<<flag;
                TreeNode *node = q.front();
             
                if(!flag && (prev >= node->val || !(node->val&1))) return false;
                
                if(flag && (prev <= node->val || (node->val&1))) return false;
                
                prev = node->val;
                q.pop();
                
                if(node->left != NULL) {
                 
                    q.push(node->left);
                }
                if(node->right != NULL) {
                
                    q.push(node->right);
                }
                k--;
                
                
            }
            
            flag = !flag;
        }
        return true;
    }
};