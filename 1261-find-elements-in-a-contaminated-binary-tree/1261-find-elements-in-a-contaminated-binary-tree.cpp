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
class FindElements {
public:
    set<int>st;
    FindElements(TreeNode* root) {
        if(root == NULL)
            return;
        root->val = 0;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()) {
            int size = q.size();
            
            while(size > 0) {
                
                TreeNode *node = q.front();
                q.pop();
               
                int index = node->val;
                st.insert(index);
                if(node->left != NULL) {
                    node->left->val = 2*index+1;
                    q.push(node->left);
                }
                if(node->right != NULL) {
                    node->right->val = 2*index+2;
                    q.push(node->right);
                }
                size--;
            }
        }
         
    }
    
    bool find(int target) {
        
        if(st.find(target) != st.end())
            return true;
        return false;
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */