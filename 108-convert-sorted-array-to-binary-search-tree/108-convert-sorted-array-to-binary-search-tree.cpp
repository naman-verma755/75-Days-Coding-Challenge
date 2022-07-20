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
    TreeNode* build(int start, int end, vector<int>&nums) {
        
        if(start > end)
            return NULL;
        
        int mid = (start+end)/2;
        TreeNode *node = new TreeNode(nums[mid]);
        
        node->left = build(start, mid-1, nums);
        node->right = build(mid+1, end, nums);
        return node;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        
        return build(0, nums.size()-1, nums);
    }
};