/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        
        vector<vector<int>>ans;
        if(root == NULL)
            return ans;
        queue<Node*>qu;
        qu.push(root);
        while(!qu.empty()) {
            int size = qu.size();
            vector<int>subAns;
            while(size > 0) {
                Node *top = qu.front();
                subAns.push_back(top->val);
                qu.pop();
                for(auto it : top->children) {
                    qu.push(it);
                }
                size--;
            }
            ans.push_back(subAns);
        }
        return ans;
        
    }
};