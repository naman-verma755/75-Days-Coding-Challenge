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
    void insert(TreeNode *leftNode, TreeNode *rightNode) {
        
        while(leftNode->right != NULL)
            leftNode = leftNode->right;
        leftNode->right = rightNode;
    }
    void deleteTreeNode(TreeNode *root, int key, TreeNode *prev, char c  ) {
        if(root == NULL)
            return;
        
        if(root->val == key) {
            
            TreeNode* leftNode = root->left;
            TreeNode* rightNode = root->right;
            root->left = NULL;
            root->right = NULL;
            if(c == 'L') {
                if(leftNode == NULL)
                    prev->left = rightNode;
                else
                {
                    prev->left = leftNode;
                    insert(leftNode, rightNode);
                }
            }
             
            if(c == 'R') {
                if(leftNode == NULL)
                    prev->right = rightNode;
                else
                {
                    prev->right = leftNode;
                    insert(leftNode, rightNode);
                }
            }
            
        }
        else
        {
            deleteTreeNode(root->left, key, root, 'L');
            deleteTreeNode(root->right, key, root, 'R');
        }
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == NULL)
            return root;
        if(root->val == key) {
            TreeNode* leftNode = root->left;
            TreeNode* rightNode = root->right;
            root->left = NULL;
            root->right == NULL;
            if(leftNode == NULL)
                return rightNode;
            insert(leftNode, rightNode);
            return leftNode;
        }
        deleteTreeNode(root, key, NULL, 'N');
        return root;
        
        
    }
};